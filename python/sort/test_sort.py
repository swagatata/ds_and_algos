import unittest

from sort_algo import bubble_sort, selection_sort, insertion_sort, merge_sort, quick_sort

class TestSortingAlgorithms(unittest.TestCase):

    def test_bubble_sort(self):
        # Test bubble sort on an empty list
        self.assertEqual(bubble_sort([]), [])

        # Test bubble sort on a list with one element
        self.assertEqual(bubble_sort([1]), [1])

        # Test bubble sort on a list with two elements
        self.assertEqual(bubble_sort([2, 1]), [1, 2])

        # Test bubble sort on a list with three elements
        self.assertEqual(bubble_sort([3, 2, 1]), [1, 2, 3])

        # Test bubble sort on a list with randomly ordered elements
        self.assertEqual(bubble_sort([4, 1, 3, 2]), [1, 2, 3, 4])

    def test_selection_sort(self):
        # Test selection sort on an empty list
        self.assertEqual(selection_sort([]), [])

        # Test selection sort on a list with one element
        self.assertEqual(selection_sort([1]), [1])

        # Test selection sort on a list with two elements
        self.assertEqual(selection_sort([2, 1]), [1, 2])

        # Test selection sort on a list with three elements
        self.assertEqual(selection_sort([3, 2, 1]), [1, 2, 3])

        # Test selection sort on a list with randomly ordered elements
        self.assertEqual(selection_sort([4, 1, 3, 2]), [1, 2, 3, 4])

    def test_insertion_sort(self):
        # Test insertion sort on an empty list
        self.assertEqual(insertion_sort([]), [])

        # Test insertion sort on a list with one element
        self.assertEqual(insertion_sort([1]), [1])

        # Test insertion sort on a list with two elements
        self.assertEqual(insertion_sort([2, 1]), [1, 2])

        # Test insertion sort on a list with three elements
        self.assertEqual(insertion_sort([3, 2, 1]), [1, 2, 3])

        # Test insertion sort on a list with randomly ordered elements
        self.assertEqual(insertion_sort([4, 1, 3, 2]), [1, 2, 3, 4])

    def test_merge_sort(self):
        # Test merge sort on an empty list
        self.assertEqual(merge_sort([]), [])

        # Test merge sort on a list with one element
        self.assertEqual(merge_sort([1]), [1])

        # Test merge sort on a list with two elements
        self.assertEqual(merge_sort([2, 1]), [1, 2])

        # Test merge sort on a list with three elements
        self.assertEqual(merge_sort([3, 2, 1]), [1, 2, 3])

        # Test merge sort on a list with randomly ordered elements
        self.assertEqual(merge_sort([4, 1, 3, 2]), [1, 2, 3, 4])

    def test_quick_sort(self):
        # Test quick sort on an empty list
        self.assertEqual(quick_sort([]), [])

        # Test quick sort on a list with one element
        self.assertEqual(quick_sort([1]), [1])

        # Test quick sort on a list with two elements
        self.assertEqual(quick_sort([1, 2]), [1, 2])
        self.assertEqual(quick_sort([2, 1]), [1, 2])

        # Test quick sort on a list with three elements
        self.assertEqual(quick_sort([3, 2, 1]), [1, 2, 3])

        # Test quick sort on a list with randomly ordered elements
        self.assertEqual(quick_sort([4, 1, 3, 2]), [1, 2, 3, 4])

        self.assertEqual(quick_sort([4, 1, 2, 3]), [1, 2, 3, 4])

        self.assertEqual(quick_sort([4, 4, 4]), [4, 4, 4])
        self.assertEqual(quick_sort([4, 1, 2, 4]), [1, 2, 4, 4])
        self.assertEqual(quick_sort([-4, 1, 2, 4]), [-4, 1, 2, 4])
        self.assertEqual(quick_sort([-4, 1, 2, -4]), [-4, -4, 1, 2])
        
        # boundary cases
        self.assertEqual(quick_sort([-4, -3, -2, -1, 0, 1]), [-4, -3, -2, -1, 0, 1])
        self.assertEqual(quick_sort([-4, -3, -2, -1, 0, 1]), [-4, -3, -2, -1, 0, 1])

        assert False

if __name__ == "__main__":
    unittest.main()
