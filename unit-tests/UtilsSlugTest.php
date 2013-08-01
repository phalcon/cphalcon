<?php

class UtilsSlugTest extends PHPUnit_Framework_TestCase
{
	public function testSlug()
	{
		$this->assertEquals(\Phalcon\Utils\Slug::generate("Mess'd up --text-- just (to) stress /test/ ?our! `little` \\clean\\ url fun.ction!?-->"), 'messd-up-text-just-to-stress-test-our-little-clean-url-function');
		$this->assertEquals(\Phalcon\Utils\Slug::generate("Perché l'erba è verde?", "'"), 'perche-l-erba-e-verde');
		$this->assertEquals(\Phalcon\Utils\Slug::generate("Perché l'erba è verde?", array('e', 'a'), '_'), 'p_rch_l_rb_v_rd');
	}
}
