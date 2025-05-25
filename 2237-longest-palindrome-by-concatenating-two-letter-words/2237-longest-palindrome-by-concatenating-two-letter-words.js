/**
 * @param {string[]} words
 * @return {number}
 */
var longestPalindrome = function(words) {
    var mpp=new Map()
    let result=0;
    for(const word of words){
        const rev=word[1]+word[0]
        if(mpp.get(rev)>0){
            result+=4;
            mpp.set(rev,mpp.get(rev)-1)

        }
        else{
            mpp.set(word,(mpp.get(word)||0)+1)
        }
    }
    for(const [word,count] of mpp.entries()){
        if(word[0]==word[1] && count>0){
            result+=2;
            break;
        }
    }
    return result;
};