'''

To solve the problem, we can use binary search to find the minimum time required to complete totalTrips trips. We can set the lower bound left to 1 and the upper bound right to totalTrips * max(time), where max(time) is the maximum time required by any bus to complete a trip. We can then perform binary search on the range [left, right], and for each mid value, we can calculate the total number of trips that can be completed in that time by iterating over the time array and adding the number of trips that each bus can complete.

If the total number of trips that can be completed is greater than or equal to totalTrips, we update the upper bound to mid, since we want to find the minimum possible time. Otherwise, we update the lower bound to mid + 1.

Once the binary search is complete, we return the lower bound as the minimum time required to complete all the trips.
'''
class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        left, right = 1, totalTrips * min(time)
        while left < right:
            mid = (left + right) // 2
            trips = sum((mid // t) for t in time)
            if trips >= totalTrips:
                right = mid
            else:
                left = mid + 1
        return left
