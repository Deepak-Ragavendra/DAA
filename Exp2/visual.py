import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_excel("insertion/insertion_analysis.xlsx")
plt.figure(figsize=(10,6))
plt.plot(df[df["Scenario"]=="Best Case"]["Input Size"], df[df["Scenario"]=="Best Case"]["Time Taken"],marker="o", label="Best Case", color="red")
plt.plot(df[df["Scenario"]=="Worst Case"]["Input Size"], df[df["Scenario"]=="Worst Case"]["Time Taken"],marker="o", label="Worst Case", color="orange")
plt.plot(df[df["Scenario"]=="Average Case"]["Input Size"], df[df["Scenario"]=="Average Case"]["Time Taken"],marker="o", label="Average Case", color="blue")

plt.title("Insertion Sort Analysis")
plt.xlabel("Input Size")
plt.ylabel("Time Taken (seconds)")
plt.legend()
plt.savefig('insertion_sort_analysis.png')
print(df)
