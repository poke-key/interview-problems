def compute_min_max_money(prices, extra_books):
    prices.sort()
    n = len(prices)

    #min money - sell cheap, give away expensive for free
    min_money = 0
    i = 0  #pointer to the lowest price cuz we wanna sell that
    j = n - 1  #highest ptr
    while i <= j:
        min_money += prices[i]
        i += 1
        j -= extra_books  # remove the most expensive free books

    #max money we can get by selling most expensive and give cheapest for free
    max_money = 0
    i = n - 1  #reverse pointer from before
    j = 0     

    while i >= j:
        max_money += prices[i]
        i -= 1
        j += extra_books  #remove the cheapest free books

    return min_money, max_money


#take in input
n = int(input())
prices = list(map(int, input().split()))
extra_books = int(input())

min_money, max_money = compute_min_max_money(prices, extra_books)

#output
print(min_money)
print(max_money)
