<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Fixtures\Helpers;

use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

class TagSetup
{
    use DiTrait;

    protected $doctype = Tag::HTML5;

    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');

        Tag::setDI($this->container);
        Tag::resetInput();

        $this->doctype = $this->docTypeStringToConstant(
            Tag::getDocType()
        );
    }

    /**
     * Converts a doctype code to a string output
     *
     * @return string
     * @since  2014-09-04
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    protected function docTypeStringToConstant(string $doctype)
    {
        $tab = "\t";

        switch ($doctype) {
            case '<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 3.2 Final//EN">' . PHP_EOL:
                return Tag::HTML32;

            case '<!DOCTYPE html ' .
                'PUBLIC "-//W3C//DTD HTML 4.01//EN"' .
                PHP_EOL .
                $tab .
                '"http://www.w3.org/TR/html4/strict.dtd">' . PHP_EOL:
                return Tag::HTML401_STRICT;

            case '<!DOCTYPE html ' .
                'PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"' .
                PHP_EOL .
                $tab .
                '"http://www.w3.org/TR/html4/loose.dtd">' . PHP_EOL:
                return Tag::HTML401_TRANSITIONAL;

            case '<!DOCTYPE html ' .
                'PUBLIC "-//W3C//DTD HTML 4.01 Frameset//EN"' .
                PHP_EOL .
                $tab .
                '"http://www.w3.org/TR/html4/frameset.dtd">' .
                PHP_EOL:
                return Tag::HTML401_FRAMESET;

            case '<!DOCTYPE html ' .
                'PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"' .
                PHP_EOL .
                $tab .
                '"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">' .
                PHP_EOL:
                return Tag::XHTML10_STRICT;

            case '<!DOCTYPE html ' .
                'PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"' .
                PHP_EOL .
                $tab .
                '"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">' .
                PHP_EOL:
                return Tag::XHTML10_TRANSITIONAL;

            case '<!DOCTYPE html ' .
                'PUBLIC "-//W3C//DTD XHTML 1.0 Frameset//EN"' .
                PHP_EOL .
                $tab .
                '"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd">' .
                PHP_EOL:
                return Tag::XHTML10_FRAMESET;

            case '<!DOCTYPE html ' .
                'PUBLIC "-//W3C//DTD XHTML 1.1//EN"' .
                PHP_EOL .
                $tab .
                '"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">' .
                PHP_EOL:
                return Tag::XHTML11;

            case '<!DOCTYPE html ' .
                'PUBLIC "-//W3C//DTD XHTML 2.0//EN"' .
                PHP_EOL .
                $tab .
                '"http://www.w3.org/MarkUp/DTD/xhtml2.dtd">' .
                PHP_EOL:
                return Tag::XHTML20;

            default:
                return Tag::HTML5;
        }
    }

    public function _after(UnitTester $I)
    {
        Tag::setDocType($this->doctype);

        Tag::resetInput();
    }

    /**
     * Runs a doctype test, one for each doctype
     */
    protected function runDoctypeTest(UnitTester $I, int $doctype)
    {
        Tag::resetInput();

        Tag::setDocType($doctype);

        $expected = $this->docTypeToString($doctype);

        $I->assertEquals(
            $expected,
            Tag::getDocType()
        );
    }

    /**
     * Converts a doctype code to a string output
     *
     * @return string
     * @since  2014-09-04
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    protected function docTypeToString(int $doctype)
    {
        $tab = "\t";

        switch ($doctype) {
            case 1:
                return '<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 3.2 Final//EN">' . PHP_EOL;

            case 2:
                return '<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN"' . PHP_EOL .
                    $tab .
                    '"http://www.w3.org/TR/html4/strict.dtd">' . PHP_EOL;

            case 3:
                return '<!DOCTYPE html ' .
                    'PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"' . PHP_EOL .
                    $tab .
                    '"http://www.w3.org/TR/html4/loose.dtd">' . PHP_EOL;

            case 4:
                return '<!DOCTYPE html ' .
                    'PUBLIC "-//W3C//DTD HTML 4.01 Frameset//EN"' . PHP_EOL .
                    $tab .
                    '"http://www.w3.org/TR/html4/frameset.dtd">' . PHP_EOL;

            case 6:
                return '<!DOCTYPE html ' .
                    'PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"' . PHP_EOL .
                    $tab .
                    '"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">' . PHP_EOL;

            case 7:
                return '<!DOCTYPE html ' .
                    'PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"' . PHP_EOL .
                    $tab .
                    '"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">' . PHP_EOL;

            case 8:
                return '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Frameset//EN"' . PHP_EOL .
                    $tab .
                    '"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd">' . PHP_EOL;

            case 9:
                return '<!DOCTYPE html ' .
                    'PUBLIC "-//W3C//DTD XHTML 1.1//EN"' . PHP_EOL .
                    $tab .
                    '"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">' . PHP_EOL;

            case 10:
                return '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 2.0//EN"' . PHP_EOL .
                    $tab .
                    '"http://www.w3.org/MarkUp/DTD/xhtml2.dtd">' . PHP_EOL;

            default:
                return '<!DOCTYPE html>' . PHP_EOL;
        }
    }

    /**
     * Runs the test for a Tag::$function with $options
     */
    protected function testFieldParameter(UnitTester $I, string $function, $options, string $expected, bool $xhtml = false, string $set = '')
    {
        if ($xhtml) {
            Tag::setDocType(
                Tag::XHTML10_STRICT
            );

            $expected .= ' />';
        } else {
            Tag::setDocType(
                Tag::HTML5
            );

            $expected .= '>';
        }

        if ($set) {
            Tag::{$set}('x_name', 'x_value');
        }

        $actual = Tag::$function($options);

        $I->assertEquals($expected, $actual);
    }
}
