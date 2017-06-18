<?php

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Tag\TagDoctypeTest
 * Tests the \Phalcon\Tag component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Tag
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TagDoctypeTest extends UnitTest
{
    /**
     * executed after each test
     */
    protected function _after()
    {
        // Setting the doctype to HTML5 for other tests to run smoothly
        Tag::setDocType(Tag::HTML5);
    }

    /**
     * Tests the setting the doctype 3.2
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-05
     */
    public function testDoctypeSet32Final()
    {
        $this->specify(
            "setDoctype to 3.2 is not correct",
            function () {
                $this->runDoctypeTest(Tag::HTML32);
            }
        );
    }

    /**
     * Tests the setting the doctype 4.01 Strict
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet401()
    {
        $this->specify(
            "setDoctype to HTML 4.01 Strict is not correct",
            function () {
                $this->runDoctypeTest(Tag::HTML401_STRICT);
            }
        );
    }

    /**
     * Tests the setting the doctype 4.01 Transitional
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet401Transitional()
    {
        $this->specify(
            "setDoctype to HTML 4.01 Transitional is not correct",
            function () {
                $this->runDoctypeTest(Tag::HTML401_TRANSITIONAL);
            }
        );
    }

    /**
     * Tests the setting the doctype 4.01 Frameset
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet401Frameset()
    {
        $this->specify(
            "setDoctype to HTML 4.01 Frameset is not correct",
            function () {
                $this->runDoctypeTest(Tag::HTML401_FRAMESET);
            }
        );
    }

    /**
     * Tests the setting the doctype 5
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet5()
    {
        $this->specify(
            "setDoctype to HTLM5 is not correct",
            function () {
                $this->runDoctypeTest(Tag::HTML5);
            }
        );
    }

    /**
     * Tests the setting the doctype 1.0 Strict
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet10Strict()
    {
        $this->specify(
            "setDoctype to XHTML 1.0 Strict is not correct",
            function () {
                $this->runDoctypeTest(Tag::XHTML10_STRICT);
            }
        );
    }

    /**
     * Tests the setting the doctype 1.0 Transitional
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet10Transitional()
    {
        $this->specify(
            "setDoctype to XHTML 1.0 Transitional is not correct",
            function () {
                $this->runDoctypeTest(Tag::XHTML10_TRANSITIONAL);
            }
        );
    }

    /**
     * Tests the setting the doctype 1.0 Frameset
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet10Frameset()
    {
        $this->specify(
            "setDoctype to XHTML 1.0 Frameset is not correct",
            function () {
                $this->runDoctypeTest(Tag::XHTML10_FRAMESET);
            }
        );
    }

    /**
     * Tests the setting the doctype 1.1
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet11()
    {
        $this->specify(
            "setDoctype to XHTML 1.1 is not correct",
            function () {
                $this->runDoctypeTest(Tag::XHTML11);
            }
        );
    }

    /**
     * Tests the setting the doctype 2.0
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSet20()
    {
        $this->specify(
            "setDoctype to XHTML 2.0 is not correct",
            function () {
                $this->runDoctypeTest(Tag::XHTML20);
            }
        );
    }

    /**
     * Tests the setting the doctype to a wrong setting
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-09-04
     */
    public function testDoctypeSetWrongParameter()
    {
        $this->specify(
            "setDoctype to a wrong setting is not correct",
            function () {
                $this->runDoctypeTest(99);
            }
        );
    }

    /**
     * Runs a doctype test, one for each doctype
     *
     * @param integer $doctype
     */
    protected function runDoctypeTest($doctype)
    {
        Tag::resetInput();
        Tag::setDocType($doctype);

        $expected = $this->docTypeToString($doctype);
        $actual   = Tag::getDocType();

        Tag::setDocType(Tag::HTML5);

        expect($actual)->equals($expected);
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
