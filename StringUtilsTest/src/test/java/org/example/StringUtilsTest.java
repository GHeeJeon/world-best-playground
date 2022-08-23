package org.example;

import org.apache.commons.lang3.StringUtils;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

public class StringUtilsTest {
    //given
    //when
    //then

    @test
    public void testIsEmpty() {
        assertTrue("문자열이 null 이거나 비어 있으면 true", StringUtils.isEmpty(""));
        assertTrue("문자열이 null 이거나 비어 있으면 true", StringUtils.isEmpty(" "));
        assertTrue("문자열이 null 이거나 비어 있으면 true", StringUtils.isEmpty("GHeeJeon"));
    }

    public void testIsBlank() {
        assertTrue("문자열이 비어 있거나 null 이거나 공백만 있으면 있으면 true", StringUtils.isBlank(""));
        assertTrue("문자열이 비어 있거나 null 이거나 공백만 있으면 있으면 true", StringUtils.isBlank(" "));
        assertTrue("문자열이 비어 있거나 null 이거나 공백만 있으면 있으면 true", StringUtils.isBlank("GHeeJeon"));
    }

    public void testIsAlpha() {
        assertTrue("문자열에 오직 유니코드만 포함되어 있다면 true", StringUtils.isAlpha("GHeeJeon"));
        assertTrue("문자열에 오직 유니코드만 포함되어 있다면 true", StringUtils.isAlpha("전지희"));
    }

    public void testLength() {
        assertEquals("문자열 길이, null 일 경우 0", 8, StringUtils.length("GHeeJeon"));
        assertEquals("문자열 길이, null 일 경우 0", 0, StringUtils.length(""));
    }

    public void testSwapCase() {
        assertEquals("대문자는 소문자로, 소문자는 대문자로", "ghEEjEON", StringUtils.swapCase("GHeeJeon"));
        assertEquals("대문자는 소문자로, 소문자는 대문자로", "GHeeJeon", StringUtils.swapCase("ghEEjEON"));
    }

    public void testChomp() {
        assertEquals("맨 뒤 공백문자 하나를 먹어버린다. 없음 말고", "GHeeJeon", StringUtils.chomp("GHeeJeon"));
        assertEquals("맨 뒤 공백문자 하나를 먹어버린다. 없음 말고", "GHeeJeon", StringUtils.chomp("GHeeJeon\n"));
        assertEquals("맨 뒤 공백문자 하나를 먹어버린다. 없음 말고", "GHeeJeon\n", StringUtils.chomp("GHeeJeon\n\n"));
        assertEquals("맨 뒤 공백문자 하나를 먹어버린다. 없음 말고", "GHeeJeon\nGHeeJeon", StringUtils.chomp("GHeeJeon\nGHeeJeon\n"));

    }
}
