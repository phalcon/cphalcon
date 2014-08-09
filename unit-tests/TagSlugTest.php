<?php

class TagSlugTest extends PHPUnit_Framework_TestCase
{
	public function testSlug()
	{
		$this->assertEquals(\Phalcon\Tag::friendlyTitle("Mess'd up --text-- just (to) stress /test/ ?our! `little` \\clean\\ url fun.ction!?-->"), 'messd-up-text-just-to-stress-test-our-little-clean-url-function');
		$this->assertEquals(\Phalcon\Tag::friendlyTitle("Perché l'erba è verde?", "-", true, "'"), 'perche-l-erba-e-verde');
		$this->assertEquals(\Phalcon\Tag::friendlyTitle("Perché l'erba è verde?", "_", false, array('e', 'a')), 'P_rch_l_rb_v_rd');
	}
}
