<?php
/**
 * TagDoctypeCest.php
 * \Phalcon\Tag
 *
 * Tests the \Phalcon\Tag component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Tag;

use \CodeGuy;
use \Phalcon\Tag as PhTag;

class TagDoctypeCest extends TagBase
{
    /**
     * Setting the doctype to HTML5 for other tests to run smoothly
     */
    public function _after()
    {
        PhTag::setDocType(PhTag::HTML5);
    }

    /**
     * Tests the setting the doctype 3.2
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testDoctypeSet32Final(CodeGuy $I)
    {
        $this->runDoctypeTest($I, PhTag::HTML32);
    }

    /**
     * Tests the setting the doctype 4.01 Strict
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testDoctypeSet401(CodeGuy $I)
    {
        $this->runDoctypeTest($I, PhTag::HTML401_STRICT);
    }

    /**
     * Tests the setting the doctype 4.01 Transitional
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testDoctypeSet401Transitional(CodeGuy $I)
    {
        $this->runDoctypeTest($I, PhTag::HTML401_TRANSITIONAL);
    }

    /**
     * Tests the setting the doctype 4.01 Frameset
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testDoctypeSet401Frameset(CodeGuy $I)
    {
        $this->runDoctypeTest($I, PhTag::HTML401_FRAMESET);
    }

    /**
     * Tests the setting the doctype 5
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testDoctypeSet5(CodeGuy $I)
    {
        $this->runDoctypeTest($I, PhTag::HTML5);
    }

    /**
     * Tests the setting the doctype 1.0 Strict
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testDoctypeSet10Strict(CodeGuy $I)
    {
        $this->runDoctypeTest($I, PhTag::XHTML10_STRICT);
    }

    /**
     * Tests the setting the doctype 1.0 Transitional
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testDoctypeSet10Transitional(CodeGuy $I)
    {
        $this->runDoctypeTest($I, PhTag::XHTML10_TRANSITIONAL);
    }

    /**
     * Tests the setting the doctype 1.0 Frameset
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testDoctypeSet10Frameset(CodeGuy $I)
    {
        $this->runDoctypeTest($I, PhTag::XHTML10_FRAMESET);
    }

    /**
     * Tests the setting the doctype 1.1
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testDoctypeSet11(CodeGuy $I)
    {
        $this->runDoctypeTest($I, PhTag::XHTML11);
    }

    /**
     * Tests the setting the doctype 2.0
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testDoctypeSet20(CodeGuy $I)
    {
        $this->runDoctypeTest($I, PhTag::XHTML20);
    }

    /**
     * Tests the setting the doctype to a wrong setting
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param CodeGuy $I
     */
    public function testDoctypeSetWrongParameter(CodeGuy $I)
    {
        $this->runDoctypeTest($I, 99);
    }

    /**
     * Runs a doctype test, one for each doctype
     *
     * @param CodeGuy $I
     * @param integer $doctype
     */
    private function runDoctypeTest(\CodeGuy $I, $doctype)
    {
        PhTag::setDocType($doctype);

        $expected = $this->docTypeToString($doctype);
        $actual   = PhTag::getDocType();

        PhTag::setDocType(PhTag::HTML5);

        $I->assertEquals(
            $expected,
            $actual,
            sprintf($this->message, 'Doctype (' . $expected . ')')
        );
    }

    /**
     * Converts a doctype code to a string output
     * 
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     *
     * @param $doctype
     *
     * @return string
     */
    private function docTypeToString($doctype)
	{
        $tab = "\t";

		switch ($doctype) {
			case 1:
                return '<!DOCTYPE html ' .
                       'PUBLIC "-//W3C//DTD HTML 3.2 Final//EN">' . PHP_EOL;
			case 2:
                return '<!DOCTYPE html ' .
                       'PUBLIC "-//W3C//DTD HTML 4.01//EN"' .
                       PHP_EOL .
                       $tab .
                       '"http://www.w3.org/TR/html4/strict.dtd">' . PHP_EOL;
			case 3:
                return '<!DOCTYPE html ' .
                       'PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"' .
                       PHP_EOL .
                       $tab .
                       '"http://www.w3.org/TR/html4/loose.dtd">' . PHP_EOL;
			case 4:
                return '<!DOCTYPE html ' .
                       'PUBLIC "-//W3C//DTD HTML 4.01 Frameset//EN"' .
                       PHP_EOL .
                       $tab .
                       '"http://www.w3.org/TR/html4/frameset.dtd">' .
                       PHP_EOL;
			case 6:
                return '<!DOCTYPE html ' .
                       'PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"' .
                       PHP_EOL .
                       $tab .
                       '"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">' .
                       PHP_EOL;
			case 7:
                return '<!DOCTYPE html ' .
                       'PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"' .
                       PHP_EOL .
                       $tab .
                       '"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">' .
                       PHP_EOL;
			case 8:
                return '<!DOCTYPE html ' .
                       'PUBLIC "-//W3C//DTD XHTML 1.0 Frameset//EN"' .
                       PHP_EOL .
                       $tab .
                       '"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd">' .
                       PHP_EOL;
			case 9:
                return '<!DOCTYPE html ' .
                       'PUBLIC "-//W3C//DTD XHTML 1.1//EN"' .
                       PHP_EOL .
                       $tab .
                       '"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">' .
                       PHP_EOL;
			case 10:
                return '<!DOCTYPE html ' .
                       'PUBLIC "-//W3C//DTD XHTML 2.0//EN"' .
                       PHP_EOL .
                       $tab .
                       '"http://www.w3.org/MarkUp/DTD/xhtml2.dtd">' .
                       PHP_EOL;
            default:
                return '<!DOCTYPE html>' . PHP_EOL;
		}
    }
}
