stock_prices = [int(x) for x in open('stocks_input').readlines()]

min = stock_prices[0]
min_profit = 0
min_i = 0
low_i = 0
high_i = 0

for i in xrange(len(stock_prices)):
    if stock_prices[i] - min > min_profit:
        min_profit = stock_prices[i] - min
        low_i = min_i
        high_i = i

    if stock_prices[i] < min:
        min_i = i
        min = stock_prices[i]

print min_profit, stock_prices[high_i], stock_prices[low_i]
