package org.example;

import org.apache.commons.lang3.StringUtils;
import org.junit.Test;
import org.junit.jupiter.api.DisplayName;

import static org.junit.Assert.*;

public class StringUtilsTest {
    //given
    //when
    //then

    @Test
    @DisplayName("StringUtils.isEmpty 테스트")
    public void testIsEmpty() {
        //given

        //when

        //then
        assertTrue("문자열이 null 이면 true", StringUtils.isEmpty(null));
        assertTrue("문자열이 비어 있으면 true", StringUtils.isEmpty(""));
        assertFalse("문자열이 비어 있지 않으면 false", StringUtils.isEmpty("GHeeJeon"));
        assertFalse("문자열(공백포함)이 비어 있지 않으면 false", StringUtils.isEmpty("  GHeeJeon  "));
        assertFalse("문자열에 공백만 있어도 false", StringUtils.isEmpty(" "));
    }

    @Test
    @DisplayName("StringUtils.isBlank 테스트")
    public void testIsBlank() {
        //given

        //when

        //then
        assertTrue("문자열이 null 이면 true", StringUtils.isBlank(null));
        assertTrue("문자열이 비어 있으면 true", StringUtils.isBlank(""));
        assertTrue("문자열에 공백만 있다면 true", StringUtils.isBlank(" "));
        assertFalse("문자열이 비어 있지 않으면 false", StringUtils.isBlank("GHeeJeon"));
        assertFalse("문자열(공백포함)이 비어 있지 않으면 false", StringUtils.isBlank("  GHeeJeon  "));
    }

    @Test
    @DisplayName("StringUtils.isAlpha 테스트")
    public void testIsAlpha() {
        //given

        //when

        //then
        assertFalse("문자열이 null 이면 false", StringUtils.isAlpha(null));
        assertFalse("문자열이 비어 있으면 false", StringUtils.isAlpha(""));
        assertFalse("문자열에 공백만 있다면 false", StringUtils.isAlpha(" "));
        assertTrue("문자열(영어)에 오직 유니코드(문자)만 포함되어 있다면 true", StringUtils.isAlpha("GHeeJeon"));
        assertTrue("문자열(한글)에 오직 유니코드(문자)만 포함되어 있다면 true", StringUtils.isAlpha("전지희"));
    }

    @Test
    @DisplayName("StringUtils.length 테스트")
    public void testLength() {
        //given

        //when

        //then
        assertEquals("문자열이 null 이면 0", 0, StringUtils.length(null));
        assertEquals("문자열이 비어 있으면(길이가 0이면) 0", 0, StringUtils.length(""));
        assertEquals("문자열이 비어 있지 않으면 길이 반환", 8, StringUtils.length("GHeeJeon"));
    }

    @Test
    @DisplayName("StringUtils.swapCase 테스트")
    public void testSwapCase() {
        //given

        //when

        //then
        assertEquals("대문자는 소문자로, 소문자는 대문자로", "ghEEjEON", StringUtils.swapCase("GHeeJeon"));
        assertEquals("대문자는 소문자로, 소문자는 대문자로", "GHeeJeon", StringUtils.swapCase("ghEEjEON"));
    }

    @Test
    @DisplayName("StringUtils.chomp 테스트")
    public void testChomp() {
        //given

        //when

        //then
        assertNull("문자열이 null 이면 null", StringUtils.chomp(null));
        assertEquals("문자열이 비어 있으면 그대로 반환", "", StringUtils.chomp(""));
        assertEquals("문자열에 \\n 만 있다면 지우고 반환 ", "", StringUtils.chomp("\n"));
        assertEquals("문자열에 \\r 만 있다면 지우고 반환", "", StringUtils.chomp("\r"));
        assertEquals("문자열에 \\r\\n 만 있다면 지우고 반환(윈도우의 개행은 \\r\\n 이 합쳐진 형태)", "", StringUtils.chomp("\r\n"));
        assertEquals("맨 뒤 \\n 이 있다면 지우고 반환 ", "GHeeJeon", StringUtils.chomp("GHeeJeon\n"));
        assertEquals("맨 뒤 \\r 이 있다면 지우고 반환", "GHeeJeon", StringUtils.chomp("GHeeJeon\r"));
        assertEquals("맨 뒤 \\r\\n 이 있다면 지우고 반환(윈도우의 개행은 \\r\\n 이 합쳐진 형태)", "GHeeJeon", StringUtils.chomp("GHeeJeon\r\n"));
        assertEquals("맨 뒤 \\n\\r 이 있다면 \\r 만 지우고 반환(개별 문자 취급)", "GHeeJeon\n", StringUtils.chomp("GHeeJeon\n\r"));
        assertEquals("맨 뒤 개행 문자가 여러 개일 경우 하나만 지우고 반환", "GHeeJeon\n", StringUtils.chomp("GHeeJeon\n\n"));
        assertEquals("문자열 사이에 개행이 있을 경우 무시, 맨 뒤 개행 문자만 지우고 그대로 반환", "GHeeJeon\nGHeeJeon", StringUtils.chomp("GHeeJeon\nGHeeJeon\n"));
    }
}
