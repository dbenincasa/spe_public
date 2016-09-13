subroutine matmul(n,a,b,c)
   implicit none
   integer, intent(in):: n
   real(8), dimension(n,n)::a,b
   real(8), dimension(n,n)::c
   integer :: i,j,k

   ! this is the fastest looping order: 
   ! - j is always a column index, and should therefore be iterated the least
   ! - i is always a row order, so it should be used in the innermost loop
   ! - k appears as both a row index and column index, so it should be put after j and before i
   do j=1,n
      do k=1,n
         do i=1,n
            c(i,j)=c(i,j)+a(i,k)*b(k,j)
         end do
      end do
   end do 


end subroutine 
