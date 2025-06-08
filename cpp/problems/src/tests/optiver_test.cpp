#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <optional>
#include <algorithm>

using namespace std;

// Example class to test
class OrderBook {
public:
    struct Order {
        int price;
        int quantity;
        string orderId;
        
        // Default constructor
        Order() : price(0), quantity(0) {}
        
        // Parameterized constructor
        Order(int p, int q, string id) : price(p), quantity(q), orderId(id) {}
        
        bool operator==(const Order& other) const {
            return price == other.price && 
                   quantity == other.quantity && 
                   orderId == other.orderId;
        }
    };

    // Add a new order to the book
    void addOrder(const Order& order) {
        orders[order.orderId] = order;
    }

    // Remove an order from the book
    bool removeOrder(const string& orderId) {
        return orders.erase(orderId) > 0;
    }

    // Get an order by ID
    std::optional<Order> getOrder(const string& orderId) const {
        auto it = orders.find(orderId);
        if (it == orders.end()) return std::nullopt;
        return it->second;
    }

    // Get all orders
    vector<Order> getAllOrders() const {
        vector<Order> result;
        for (const auto& [id, order] : orders) {
            result.push_back(order);
        }
        return result;
    }

private:
    unordered_map<string, Order> orders;
};

// Test fixture for OrderBook tests
class OrderBookTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Common setup code for all tests
        book = OrderBook();
    }

    void TearDown() override {
        // Common cleanup code for all tests
    }

    OrderBook book;
};

// Basic test cases
TEST_F(OrderBookTest, AddAndGetOrder) {
    OrderBook::Order order(100, 10, "order1");
    book.addOrder(order);
    
    auto result = book.getOrder("order1");
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(result->price, 100);
    EXPECT_EQ(result->quantity, 10);
    EXPECT_EQ(result->orderId, "order1");
}

TEST_F(OrderBookTest, RemoveOrder) {
    OrderBook::Order order(100, 10, "order1");
    book.addOrder(order);
    
    EXPECT_TRUE(book.removeOrder("order1"));
    EXPECT_FALSE(book.getOrder("order1").has_value());
}

TEST_F(OrderBookTest, GetNonExistentOrder) {
    EXPECT_FALSE(book.getOrder("nonexistent").has_value());
}

TEST_F(OrderBookTest, GetAllOrders) {
    book.addOrder(OrderBook::Order(100, 10, "order1"));
    book.addOrder(OrderBook::Order(200, 20, "order2"));
    
    auto orders = book.getAllOrders();
    EXPECT_EQ(orders.size(), 2);
    
    // Sort orders by price for consistent testing
    std::sort(orders.begin(), orders.end(), 
         [](const OrderBook::Order& a, const OrderBook::Order& b) { return a.price < b.price; });
    
    EXPECT_EQ(orders[0].price, 100);
    EXPECT_EQ(orders[0].quantity, 10);
    EXPECT_EQ(orders[0].orderId, "order1");
    
    EXPECT_EQ(orders[1].price, 200);
    EXPECT_EQ(orders[1].quantity, 20);
    EXPECT_EQ(orders[1].orderId, "order2");
}

// Parameterized test for different order scenarios
class OrderBookPTest : public ::testing::TestWithParam<tuple<OrderBook::Order, bool>> {
protected:
    void SetUp() override {
        book = OrderBook();
    }

    OrderBook book;
};

TEST_P(OrderBookPTest, AddAndRemoveOrder) {
    auto [order, shouldSucceed] = GetParam();
    
    book.addOrder(order);
    auto result = book.getOrder(order.orderId);
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(*result, order);
    
    EXPECT_EQ(book.removeOrder(order.orderId), shouldSucceed);
    EXPECT_FALSE(book.getOrder(order.orderId).has_value());
}

INSTANTIATE_TEST_SUITE_P(
    OrderBookPTest,
    OrderBookPTest,
    ::testing::Values(
        make_tuple(OrderBook::Order(100, 10, "order1"), true),
        make_tuple(OrderBook::Order(200, 20, "order2"), true),
        make_tuple(OrderBook::Order(300, 30, "order3"), true)
    )
); 