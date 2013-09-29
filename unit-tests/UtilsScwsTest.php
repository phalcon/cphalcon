<?php

class UtilsScwsTest extends PHPUnit_Framework_TestCase
{
	public function testScws()
	{
		$scws = new Phalcon\Utils\Scws('utf8');
		$scws->set_dict("unit-tests/config/test.dict.xdb");
		$scws->set_rule("unit-tests/config/test.rule.ini");
		$scws->send_text("我是一个中国人，我热爱和平，热爱生命。");
		
		$tmp = '';
		$tops = $scws->get_tops(5);
		foreach($tops as $top) {
			$tmp = $tmp ? $tmp.'|'.$top['word'] : $top['word'];
		}
		$this->assertEquals($tmp, '热爱生命|和平|中国人|一个');

		$tmp = '';
		while ($tops = $scws->get_result())
		{
			foreach($tops as $top) {
				$tmp = $tmp ? $tmp.'|'.$top['word'] : $top['word'];
			}
		}
		$this->assertEquals($tmp, '我|是|一个|中国人|，|我|热爱|和平|，|热爱生命|。');

		$scws->send_text("I am a Chinese, I love peace, love life.");		
		$tmp = '';
		$tops = $scws->get_tops(5);
		foreach($tops as $top) {
			$tmp = $tmp ? $tmp.'|'.$top['word'] : $top['word'];
		}
		$this->assertEquals($tmp, 'love|Chinese|peace|life|am');

		$tmp = '';
		while ($tops = $scws->get_result())
		{
			foreach($tops as $top) {
				$tmp = $tmp ? $tmp.'|'.$top['word'] : $top['word'];
			}
		}

		$this->assertEquals($tmp, 'I|am|a|Chinese|,|I|love|peace|,|love|life|.');
	}
}
