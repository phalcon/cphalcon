<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Meta;

use Codeception\Example;
use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Meta;
use Phalcon\Html\TagFactory;
use UnitTester;

use const PHP_EOL;

/**
 * Class UnderscoreInvokeCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Meta
 */
class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Meta :: __invoke()
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
    public function htmlHelperMetaUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Meta - __invoke() ' . $example['message']);

        $escaper = new Escaper();
        $helper  = new Meta($escaper);

        $result = $helper($example['indent'], $example['delimiter'])
            ->add($example['add'])
            ->addHttp($example['http'][0], $example['http'][1])
            ->addName($example['name'][0], $example['name'][1])
            ->addProperty($example['property'][0], $example['property'][1]);

        $expected = $example['result'];
        $actual   = (string) $result;
        $I->assertEquals($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('meta');
        $result  = $locator($example['indent'], $example['delimiter'])
            ->add($example['add'])
            ->addHttp($example['http'][0], $example['http'][1])
            ->addName($example['name'][0], $example['name'][1])
            ->addProperty($example['property'][0], $example['property'][1]);

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
                'indent'    => '    ',
                'delimiter' => PHP_EOL,
                'add'       => [
                    "charset" => 'utf-8',
                ],
                'http'      => [
                    "X-UA-Compatible",
                    "IE=edge",
                ],
                'name'      => [
                    "generator",
                    "Phalcon",
                ],
                'property'  => [
                    "org:url",
                    "https://phalcon.io",
                ],
                'result'    => "    <meta charset=\"utf-8\">" . PHP_EOL
                    . "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">" . PHP_EOL
                    . "    <meta name=\"generator\" content=\"Phalcon\">" . PHP_EOL
                    . "    <meta property=\"org:url\" content=\"https://phalcon.io\">" . PHP_EOL,
            ],
            [
                'message'   => 'indent and delimiter',
                'indent'    => '--',
                'delimiter' => '+',
                'add'       => [
                    "charset" => 'utf-8',
                ],
                'http'      => [
                    "X-UA-Compatible",
                    "IE=edge",
                ],
                'name'      => [
                    "generator",
                    "Phalcon",
                ],
                'property'  => [
                    "org:url",
                    "https://phalcon.io",
                ],
                'result'    => "--<meta charset=\"utf-8\">+"
                    . "--<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">+"
                    . "--<meta name=\"generator\" content=\"Phalcon\">+"
                    . "--<meta property=\"org:url\" content=\"https://phalcon.io\">+",
            ],
        ];
    }
}
