BEGIN{
    sum = 0
}

{
    sum += $3
    print NF
    print NR

    if (NR % 2 == 0){
        print $1
    }

    bashes[$7]++;


}

END{
    print sum

    for (i in bashes){
        print i
    }
}