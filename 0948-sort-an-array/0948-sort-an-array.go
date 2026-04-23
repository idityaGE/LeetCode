func sortArray(nums []int) []int {
    mergeSort(nums, 0, len(nums) - 1)
    return nums
}

func mergeSort(nums []int, low, high int) {
    if low >= high {
        return
    }

    mid := low + (high-low)/2

    mergeSort(nums, low, mid);
    mergeSort(nums, mid+1, high);

    merge(nums, low, mid, high);
}

func merge(nums []int, low, mid, high int) {
    temp := make([]int, 0)

    left, right := low, mid + 1

    for left <= mid && right <= high {
        if nums[left] <= nums[right] {
            temp = append(temp, nums[left])
            left++
        } else {
            temp = append(temp, nums[right])
            right++
        }
    }

    for left <= mid {
        temp = append(temp, nums[left])
        left++
    }
    for right <= high {
        temp = append(temp, nums[right])
        right++
    }

    for i := low; i <= high; i++ {
        nums[i] = temp[i - low]
    }
}