package org.example;

import org.apache.commons.lang3.StringUtils;

import static org.junit.Assert.assertTrue;

public class StringUtilsTest {
    //given
    //when
    //then

    @test
    public void testIsEmpty(){
        assertTrue("문자열이 비어 있으면 true", StringUtils.isEmpty(""));
        assertTrue("문자열이 비어 있으면 true", StringUtils.isEmpty(" "));
        assertTrue("문자열이 비어 있으면 true", StringUtils.isEmpty("GHeeJeon"));
    }

    public void testIsBlank(){
        assertTrue("문자열이 비어 있거나 공백만 있으면 있으면 true", StringUtils.isBlank(""));
        assertTrue("문자열이 비어 있거나 공백만 있으면 있으면 true", StringUtils.isBlank(" "));
        assertTrue("문자열이 비어 있거나 공백만 있으면 있으면 true", StringUtils.isBlank("GHeeJeon"));
    }
}
