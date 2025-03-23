seconds = float(input())
minute = 60
hour = 60 * minute
day = 24 * hour
year = 365 * day

years = seconds // year
seconds %= year

days = seconds // day
seconds %= day

hours = seconds // hour
seconds %= hour

minutes = seconds // minute
seconds %= minute
