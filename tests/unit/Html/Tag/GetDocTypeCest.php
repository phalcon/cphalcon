<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Html\Tag;

use Codeception\Example;
use Phalcon\Html\Tag;
use UnitTester;

/**
 * Class GetDocTypeCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class GetDocTypeCest
{
    /**
     * Tests Phalcon\Html\Tag :: getDocType()
     *
     * @param UnitTester $I
     *
     * @dataProvider getDocTypes
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagGetDocType(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Tag - getDocType()');
        $doctype = $example['value'];
        $I->wantToTest(sprintf('Html\Tag - docTypeGet() - %s', $doctype));

        $tag = new Tag();

        $tag->setDocType($doctype);
        $expected = $example['string'];
        $actual   = $tag->getDocType();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getDocTypes(): array
    {
        return [
            [
                'value'  => 1,
                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">" . PHP_EOL,
            ],
//            [
//                'value'  => Tag::HTML_32,
//                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">" . PHP_EOL,
//            ],
//            [
//                'value'  => Tag::HTML401_STRICT,
//                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"" . PHP_EOL .
//                    "\t\"http://www.w3.org/TR/html4/strict.dtd\">" . PHP_EOL,
//            ],
//            [
//                'value'  => Tag::HTML401_TRANSITIONAL,
//                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"" . PHP_EOL .
//                            "\t\"http://www.w3.org/TR/html4/loose.dtd\">" . PHP_EOL,
//            ],
//            [
//                'value'  => Tag::HTML401_FRAMESET,
//                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"" . PHP_EOL .
//                            "\t\"http://www.w3.org/TR/html4/frameset.dtd\">" . PHP_EOL,
//            ],
//            [
//                'value'  => Tag::HTML5,
//                'string' => "<!DOCTYPE html>" . PHP_EOL,
//            ],
//            [
//                'value'  => Tag::XHTML10_STRICT,
//                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"" . PHP_EOL .
//                            "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">" . PHP_EOL,
//            ],
//            [
//                'value'  => Tag::XHTML10_TRANSITIONAL,
//                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"" . PHP_EOL .
//                            "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">" . PHP_EOL,
//            ],
//            [
//                'value'  => Tag::XHTML10_FRAMESET,
//                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"" . PHP_EOL .
//                            "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">" . PHP_EOL,
//            ],
//            [
//                'value'  => Tag::XHTML11,
//                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"" . PHP_EOL .
//                            "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">" . PHP_EOL,
//            ],
//            [
//                'value'  => Tag::XHTML20,
//                'string' => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"" . PHP_EOL .
//                            "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">" . PHP_EOL,
//            ],
//            [
//                'value'  => Tag::XHTML5,
//                'string' => "<!DOCTYPE html>" . PHP_EOL,
//            ],
        ];
    }
}
