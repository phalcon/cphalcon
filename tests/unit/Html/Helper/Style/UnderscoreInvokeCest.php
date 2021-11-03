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
use Phalcon\Factory\Exception;
use Phalcon\Html\Helper\Style;
use Phalcon\Html\TagFactory;
use UnitTester;

class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Style :: __invoke()
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @throws Exception
     *
     * @dataProvider getExamples
     * @since        2020-01-06
     */
    public function htmlHelperStyleUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Style - __invoke() ' . $example['message']);

        $escaper = new Escaper();
        $helper  = new Style($escaper);

        $result = $helper($example['indent'], $example['delimiter']);
        foreach ($example['add'] as $add) {
            $result->add($add[0], $add[1]);
        }

        $expected = $example['result'];
        $actual   = (string) $result;
        $I->assertEquals($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('style');

        $result = $locator($example['indent'], $example['delimiter']);
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
                'message'   => 'base',
                'indent'    => null,
                'delimiter' => null,
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
                'result'    => "    <style rel=\"stylesheet\" type=\"text/css\" "
                    . "href=\"custom.css\" media=\"screen\"></style>" . PHP_EOL
                    . "    <style rel=\"stylesheet\" type=\"text/css\" "
                    . "href=\"print.css\" media=\"print\"></style>" . PHP_EOL,
            ],
            [
                'message'   => 'with indent and delimiter',
                'indent'    => '--',
                'delimiter' => '+',
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
                'result'    => "--<style rel=\"stylesheet\" type=\"text/css\" "
                    . "href=\"custom.css\" media=\"screen\"></style>+"
                    . "--<style rel=\"stylesheet\" type=\"text/css\" "
                    . "href=\"print.css\" media=\"print\"></style>+",
            ],
        ];
    }
}
