<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Style;

use Codeception\Example;
use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Style;
use Phalcon\Html\TagFactory;
use UnitTester;

use const PHP_EOL;

/**
 * Class UnderscoreInvokeCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Style
 */
class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Style :: __invoke()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @throws Exception
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function htmlHelperStyleUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Style - __invoke() ' . $example['message']);

        $escaper = new Escaper();
        $helper  = new Style($escaper);

        $result = $helper($example['indent'], $example['delimiter']);
        $result->setStyle($example['style']);
        foreach ($example['add'] as $add) {
            $result->add($add[0], $add[1]);
        }

        $expected = $example['result'];
        $actual   = (string) $result;
        $I->assertEquals($expected, $actual);

        /**
         * Try the TagFactory
         */
        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('style');

        $result = $locator($example['indent'], $example['delimiter']);
        $result->setStyle($example['style']);
        foreach ($example['add'] as $add) {
            $result->add($add[0], $add[1]);
        }

        $actual = (string) $result;
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'message'   => 'link base',
                'indent'    => '    ',
                'delimiter' => PHP_EOL,
                'style'     => false,
                'add'       => [
                    [
                        "custom.css",
                        [],
                    ],
                    [
                        "print.css",
                        ["media" => "print"],
                    ],
                ],
                'result'    => "    <link rel=\"stylesheet\" type=\"text/css\" "
                    . "href=\"custom.css\" media=\"screen\" />" . PHP_EOL
                    . "    <link rel=\"stylesheet\" type=\"text/css\" "
                    . "href=\"print.css\" media=\"print\" />" . PHP_EOL,
            ],
            [
                'message'   => 'link with indent and delimiter',
                'indent'    => '--',
                'delimiter' => '+',
                'style'     => false,
                'add'       => [
                    [
                        "custom.css",
                        [],
                    ],
                    [
                        "print.css",
                        ["media" => "print"],
                    ],
                ],
                'result'    => "--<link rel=\"stylesheet\" type=\"text/css\" "
                    . "href=\"custom.css\" media=\"screen\" />+"
                    . "--<link rel=\"stylesheet\" type=\"text/css\" "
                    . "href=\"print.css\" media=\"print\" />+",
            ],
            [
                'message'   => 'style base',
                'indent'    => '    ',
                'delimiter' => PHP_EOL,
                'style'     => true,
                'add'       => [
                    [
                        "custom.css",
                        [],
                    ],
                    [
                        "print.css",
                        ["media" => "print"],
                    ],
                ],
                'result'    => "    <style type=\"text/css\" "
                    . "href=\"custom.css\" media=\"screen\" />" . PHP_EOL
                    . "    <style type=\"text/css\" "
                    . "href=\"print.css\" media=\"print\" />" . PHP_EOL,
            ],
            [
                'message'   => 'style with indent and delimiter',
                'indent'    => '--',
                'delimiter' => '+',
                'style'     => true,
                'add'       => [
                    [
                        "custom.css",
                        [],
                    ],
                    [
                        "print.css",
                        ["media" => "print"],
                    ],
                ],
                'result'    => "--<style type=\"text/css\" "
                    . "href=\"custom.css\" media=\"screen\" />+"
                    . "--<style type=\"text/css\" "
                    . "href=\"print.css\" media=\"print\" />+",
            ],
        ];
    }
}
