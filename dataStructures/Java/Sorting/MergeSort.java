// Author: Mason Harsh
package dataStructures.Java.Sorting;

import java.util.Arrays;

public class MergeSort {

    // Recursive merge sort function that splits the array and merges sorted halves
    public static int[] mergeSort(int[] arr) {
        int length = arr.length;
        if (length <= 1) {
            return arr; // Base case: array is already sorted
        }

        int mid = length / 2;

        // Recursively sort left and right halves
        int[] left = mergeSort(Arrays.copyOfRange(arr, 0, mid));
        int[] right = mergeSort(Arrays.copyOfRange(arr, mid, length));

        // Merge the sorted halves
        return merge(left, right);
    }

    // Merges two sorted arrays into a single sorted array
    private static int[] merge(int[] left, int[] right) {

        int[] result = new int[left.length + right.length];
        int pos = 0;

        int i = 0;
        int j = 0;

        // Compare elements from both arrays and insert the smaller one
        while (i != left.length && j != right.length) {
            // can insert a compartTo function for other types.
            if (left[i] <= right[j]) {
                result[pos] = left[i];
                i++;
            } else {
                result[pos] = right[j];
                j++;
            }
            pos++;
        }

        // Append any remaining elements from left array
        if (i != left.length) {
            for (int x = i; x < left.length; x++) {
                result[pos] = left[x];
                pos++;
            }
        }

        // Append any remaining elements from right array
        if (j != right.length) {
            for (int x = j; x < right.length; x++) {
                result[pos] = right[x];
                pos++;
            }
        }

        return result;
    }

    // Utility method to print array elements
    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    // Main method for testing
    public static void main(String[] args) {
        int[] arr = {5, 2, 9, 1, 3, 6};

        System.out.println("Before sorting:");
        printArray(arr);

        arr = mergeSort(arr); // Perform merge sort

        System.out.println("After sorting:");
        printArray(arr);
    }

}