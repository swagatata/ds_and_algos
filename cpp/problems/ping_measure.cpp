#include <iostream>
#include <string>
#include <cstdlib>
#include <regex>
#include <vector>

using namespace std;

vector<string> executeCommand(const string& command) {
    vector<string> output;
    char buffer[128];
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        cerr << "Failed to execute command" << endl;
        return output;
    }

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        output.push_back(buffer);
    }
    pclose(pipe);
    return output;
}

float extractPingTime(const string& line) {
    regex pattern("time=([0-9.]+) ms");
    smatch matches;
    if (regex_search(line, matches, pattern) && matches.size() > 1) {
        return stof(matches[1]);
    }
    return -1.0f;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <EC2_PUBLIC_IP>" << endl;
        return 1;
    }

    string ec2_ip = argv[1];
    string ping_command = "ping -c 4 " + ec2_ip;  // Send 4 ICMP packets
    
    cout << "Measuring ping time to EC2 instance at " << ec2_ip << "..." << endl;
    vector<string> output = executeCommand(ping_command);
    
    float total_time = 0.0f;
    int valid_pings = 0;
    
    for (const string& line : output) {
        float time = extractPingTime(line);
        if (time > 0) {
            total_time += time;
            valid_pings++;
            cout << "Ping time: " << time << " ms" << endl;
        }
    }
    
    if (valid_pings > 0) {
        float average_time = total_time / valid_pings;
        cout << "\nAverage round-trip time: " << average_time << " ms" << endl;
    } else {
        cout << "No valid ping responses received" << endl;
    }
    
    return 0;
} 