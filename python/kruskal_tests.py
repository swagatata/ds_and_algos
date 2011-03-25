import sys
import unittest	
from kruskal import *

kruskal_test_data = {
	'general_case_input' : 'input',
}

class KruskalTests(unittest.TestCase):
	def setUp(self):
		pass
		
	def tearDown(self):
		pass
		
	def test_single_element(self):
		self.assertEqual(kruskal(2, 1, [edge(1, 0, 1)]),(1, [edge(1,0,1)]))
		
	def test_no_element(self):
		self.assertEqual(kruskal(0, 0, []), (0, []))
		
	def test_general_case(self):
		for arg in kruskal_test_data.values():
			N, E, edges, mstcost = read_input(arg)
			mincost, mst = kruskal(N, E, edges)
			self.assertEqual(mincost, mstcost)
		
	def test_self_edge(self):
		self.assertEqual(kruskal(1, 1, [edge(1, 0, 0)]), (0, []))
		

if __name__ == "__main__":
#	kt = KruskalTests()
#	kt.test_general_case()
	unittest.main()
