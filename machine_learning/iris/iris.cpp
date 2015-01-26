#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <cassert>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

struct Entry {
	float sepal_length;
	float sepal_width;
	float petal_length;
	float petal_width;
	string class_name;
	string predicted_class;
	vector<float> prediction_values;
};

int num_estimates = 0;

float EstimateError(
	const vector<Entry>& entries, const vector<float>& weights, 
	const map<string, float>& expected) {
	vector<float> error;
	for (const auto& entry : entries) {
		auto it = expected.find(entry.class_name);
		const float expected_value = it != expected.end() ? it->second : -100.f;
		error.push_back(
			pow(expected_value - (
				weights[0] * entry.sepal_length + 
				weights[1] * entry.sepal_width + 
				weights[2] * entry.petal_length + 
				weights[3] * entry.petal_width + 
				weights[4] * 1.f), 2));
	}
	++num_estimates;
	return std::accumulate(error.begin(), error.end(), 0.f);
}

void GenerateClassification(
	const vector<Entry>& entries, const vector<float>& weights, 
	const map<string, float>& expected, vector<Entry>* misclassified) {
	for (const auto& entry : entries) {
		const float predicted_value = 
			weights[0] * entry.sepal_length +
			weights[1] * entry.sepal_width +
			weights[2] * entry.petal_length + 
			weights[3] * entry.petal_width + 
			weights[4] * 1.f;
		vector<pair<float, string>> predicted_classes;
		for (const auto& key_value : expected) {
			predicted_classes.push_back(make_pair(fabs(predicted_value - key_value.second), key_value.first));
		}
		auto it = min_element(predicted_classes.begin(), predicted_classes.end());
		if (it->second != entry.class_name) {
			misclassified->push_back(entry);
			misclassified->back().predicted_class = it->second;
			for (const auto& prediction : predicted_classes) {
				misclassified->back()
					.prediction_values.push_back(prediction.first);
			}
		}
	}
}

void GetEntries(const string& file, const int N, vector<Entry>* entries) {
	ifstream fin(file.c_str());
	for (int i = 0; i < N; ++i) {
		Entry entry;
		fin >> entry.sepal_length 
			>> entry.sepal_width 
			>> entry.petal_length 
			>> entry.petal_width 
			>> entry.class_name;
		entries->push_back(entry);
	}
	assert(entries->back().class_name == "Iris-virginica");
}

int main() {
	const int num_training_entries = 30;
	vector<Entry> entries;
	GetEntries("iris_training.in", num_training_entries, &entries);
	
	map<string, float> expected = { {"Iris-setosa", -1}, {"Iris-versicolor", 0}, {"Iris-virginica", 1}};
	vector<float> weights(5);
	std::generate(weights.begin(), weights.end(), []() { return pow(-1, rand()) * (rand() % 10); });
	const float step_size = 0.0001f;
	const float delta = 0.0001f;
	
	const int num_iters = 120000;
	for (int i = 0; i < num_iters; ++i) {
		const float current_error = EstimateError(entries, weights, expected);
		if (i % 10000 == 0 || i < 10)
			cout << "Iteration: " << i + 1 << " Error: " << current_error << '\n';
		vector<float> gradients(weights.size());
		for (int j = 0; j < weights.size(); ++j) {
			float tmp = weights[j] + delta;
			swap(weights[j], tmp);
			gradients[j] = -(EstimateError(entries, weights, expected) - current_error) / delta;
			swap(weights[j], tmp);
		}
		for (int j = 0; j < weights.size(); ++j) {
			weights[j] += gradients[j] * step_size;
		}
	}
	
	cout << "Weights: ";
	for (const auto& weight : weights) {
		cout << weight << ' ';
	}
	cout << '\n';

	vector<Entry> misclassified;
	
	const int num_test_entries = 150;
	vector<Entry> test_entries;
	GetEntries("iris.in", num_test_entries, &test_entries);
	cout << "Error on training dataset: " << EstimateError(entries, weights, expected) << '\n';
	GenerateClassification(entries, weights, expected, &misclassified);
	cout << "Training set accuracy: " 
		<< 100.f * (num_training_entries - misclassified.size()) / num_training_entries << "%\n";
	cout << "Error on test dataset: " << EstimateError(test_entries, weights, expected) << '\n';
	GenerateClassification(test_entries, weights, expected, &misclassified);
	cout << "Test set accuracy: " 
		<< 100.f * (num_test_entries - misclassified.size()) / num_test_entries << "%\n";
	for (const auto& entry : misclassified) {
		cout << "Misclassified: " 
			<< entry.sepal_length << ' '
			<< entry.sepal_width << ' '
			<< entry.petal_length << ' ' 
			<< entry.petal_width << ' '
			<< "Actual: " << entry.class_name << ' '
			<< "Predicted: " << entry.predicted_class << ' '
			<< "Label Distance: "
			<< entry.prediction_values[0] << ' '
			<< entry.prediction_values[1] << ' '
			<< entry.prediction_values[2] << '\n'
			;
	}
	cout << "Number of error estimation calls: " 
		<< num_estimates << '\n';
	return 0;
}