#!/usr/bin/python3

import sys
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv(sys.argv[1])
plt.scatter(df['WORKSET_KB'], df['SEC'])
ax = plt.gca()

ax.set_xscale('log')
plt.title('1GB memory access') 
plt.xlabel('WORKSET_SIZE [KB]',fontsize=18)
plt.ylabel('SEC',fontsize=18)

plt.savefig(sys.argv[2]);
