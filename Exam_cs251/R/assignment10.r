#step1
num_samples <- 50000
data <- rexp(num_samples, 0.2)
x <- data.frame(X = seq(1, num_samples , 1), Y = sort(data))
plot(x,main="scatter plot")

#step2
m<-matrix(data,nrow=100,ncol=500)

#step3

for(i in 1:5){
var<-m[,i]
cdf<-ecdf(var)
plot(cdf,col="orange",xlab="data",ylab="cdf(data)",main="cumulative distribution function")
plot(density(var),col="red",xlab="X",ylab="pdf(X)",main="probability density function")
cat("mean=")
print(mean(var))
cat("standard deviation=")
print(sd(var))
#print(cdf)
}

#step4

for(i in 1:500){
var<-m[,i]
if(i==1){
l<-mean(var)
}
else{
l<-c(l,mean(var))
}
}
#cat("here is RV",l,"\n")
f <- table(round(l,digits=1))
plot(f, "h", xlab="Value", ylab="Frequency")
plot(ecdf(l),col="green",xlab="Means",ylab="cdf(mean)",main="cumulative distribution function of means Y1 to Y500")
plot(density(l),col="blue",xlab="means",ylab="pdf(means)",main="probability density function of means Y1 to Y500")

#step5

cat("mean of Z" ,mean(l),"\n")
cat("standard deviation of rv Z=",sd(l),"\n")
