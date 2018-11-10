<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Unit\Tag\Helper\TagBase;
use UnitTester;

class TagDoctypeCest extends TagBase
{
    /**
     * Tests the setting the doctype 3.2
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDoctypeSet32Final(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::HTML32);
    }

    /**
     * Runs a doctype test, one for each doctype
     *
     * @param integer $doctype
     */
    protected function runDoctypeTest(UnitTester $I, $doctype)
    {
        Tag::resetInput();
        Tag::setDocType($doctype);

        $expected = $this->docTypeToString($doctype);
        $actual   = Tag::getDocType();

        Tag::setDocType(Tag::HTML5);

        $I->assertEquals($expected, $actual);
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

    /**
     * Tests the setting the doctype 4.01 Strict
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet401(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::HTML401_STRICT);
    }

    /**
     * Tests the setting the doctype 4.01 Transitional
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet401Transitional(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::HTML401_TRANSITIONAL);
    }

    /**
     * Tests the setting the doctype 4.01 Frameset
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet401Frameset(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::HTML401_FRAMESET);
    }

    /**
     * Tests the setting the doctype 5
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet5(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::HTML5);
    }

    /**
     * Tests the setting the doctype 1.0 Strict
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet10Strict(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::XHTML10_STRICT);
    }

    /**
     * Tests the setting the doctype 1.0 Transitional
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet10Transitional(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::XHTML10_TRANSITIONAL);
    }

    /**
     * Tests the setting the doctype 1.0 Frameset
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet10Frameset(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::XHTML10_FRAMESET);
    }

    /**
     * Tests the setting the doctype 1.1
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet11(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::XHTML11);
    }

    /**
     * Tests the setting the doctype 2.0
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet20(UnitTester $I)
    {
        $this->runDoctypeTest($I, Tag::XHTML20);
    }

    /**
     * Tests the setting the doctype to a wrong setting
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSetWrongParameter(UnitTester $I)
    {
        $this->runDoctypeTest($I, 99);
    }

    /**
     * executed after each test
     */
    public function _after(UnitTester $I)
    {
        // Setting the doctype to HTML5 for other tests to run smoothly
        Tag::setDocType(Tag::HTML5);
    }
}
