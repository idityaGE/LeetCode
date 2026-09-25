func twoSum(nums []int, target int) []int {
       mpp := make(map[int]int)

       for idx, num := range nums {
           needed := target - num

           if index, exists := mpp[needed]; exists {
               return []int{index, idx}
           }

           mpp[num] = idx
       }

       return nil
   }