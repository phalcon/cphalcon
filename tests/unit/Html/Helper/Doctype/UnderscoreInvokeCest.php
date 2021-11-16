<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Doctype;

use Codeception\Example;
use Phalcon\Html\Helper\Doctype;
use UnitTester;

use const PHP_EOL;

class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Doctype :: __invoke()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function htmlHelperDoctypeUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Doctype - __invoke() ' . $example['message']);

        $helper = new Doctype();

        $helper->__invoke($example['flag'], $example['delimiter']);

        $expected = $example['expected'];
        $actual   = (string) $helper;
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'message'   => 'HTML32',
                'flag'      => Doctype::HTML32,
                'delimiter' => PHP_EOL,
                'expected'  => "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">"
                    . PHP_EOL,
            ],
            [
                'message'   => 'HTML401_STRICT',
                'flag'      => Doctype::HTML401_STRICT,
                'delimiter' => PHP_EOL,
                'expected'  => "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\""
                    . PHP_EOL
                    . "\t\"http://www.w3.org/TR/html4/strict.dtd\">"
                    . PHP_EOL,
            ],
            [
                'message'   => 'HTML401_TRANSITIONAL',
                'flag'      => Doctype::HTML401_TRANSITIONAL,
                'delimiter' => PHP_EOL,
                'expected'  => "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\""
                    . PHP_EOL
                    . "\t\"http://www.w3.org/TR/html4/loose.dtd\">"
                    . PHP_EOL,
            ],
            [
                'message'   => 'HTML401_FRAMESET',
                'flag'      => Doctype::HTML401_FRAMESET,
                'delimiter' => PHP_EOL,
                'expected'  => "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\""
                    . PHP_EOL
                    . "\t\"http://www.w3.org/TR/html4/frameset.dtd\">"
                    . PHP_EOL,
            ],
            [
                'message'   => 'XHTML10_STRICT',
                'flag'      => Doctype::XHTML10_STRICT,
                'delimiter' => PHP_EOL,
                'expected'  => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\""
                    . PHP_EOL
                    . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">"
                    . PHP_EOL,
            ],
            [
                'message'   => 'XHTML10_TRANSITIONAL',
                'flag'      => Doctype::XHTML10_TRANSITIONAL,
                'delimiter' => PHP_EOL,
                'expected'  => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\""
                    . PHP_EOL
                    . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">"
                    . PHP_EOL,
            ],
            [
                'message'   => 'XHTML10_FRAMESET',
                'flag'      => Doctype::XHTML10_FRAMESET,
                'delimiter' => PHP_EOL,
                'expected'  => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\""
                    . PHP_EOL
                    . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">"
                    . PHP_EOL,
            ],
            [
                'message'   => 'XHTML11',
                'flag'      => Doctype::XHTML11,
                'delimiter' => PHP_EOL,
                'expected'  => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\""
                    . PHP_EOL
                    . "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">"
                    . PHP_EOL,
            ],
            [
                'message'   => 'XHTML20',
                'flag'      => Doctype::XHTML20,
                'delimiter' => PHP_EOL,
                'expected'  => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\""
                    . PHP_EOL
                    . "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">"
                    . PHP_EOL,
            ],
            [
                'message'   => 'HTML5',
                'flag'      => Doctype::HTML5,
                'delimiter' => PHP_EOL,
                'expected'  => "<!DOCTYPE html>" . PHP_EOL,
            ],
            [
                'message'   => 'XHTML5',
                'flag'      => Doctype::XHTML5,
                'delimiter' => PHP_EOL,
                'expected'  => "<!DOCTYPE html>" . PHP_EOL,
            ],
            [
                'message'   => 'unknown',
                'flag'      => 100,
                'delimiter' => PHP_EOL,
                'expected'  => "<!DOCTYPE html>" . PHP_EOL,
            ],
            [
                'message'   => 'XHTML11 different delimiter',
                'flag'      => Doctype::XHTML11,
                'delimiter' => '-:-',
                'expected'  => "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\""
                    . '-:-'
                    . "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">"
                    . '-:-',
            ],
        ];
    }
}
