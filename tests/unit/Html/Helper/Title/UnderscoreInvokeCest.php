<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Title;

use Codeception\Example;
use Phalcon\Html\Escaper;
use Phalcon\Html\Exception;
use Phalcon\Html\Helper\Title;
use Phalcon\Html\TagFactory;
use UnitTester;

/**
 * Class UnderscoreInvokeCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Title
 */
class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Title :: __invoke()
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
    public function htmlHelperTitleUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Title - __invoke() - ' . $example['message']);

        $escaper = new Escaper();
        $helper  = new Title($escaper);

        $indent = $example['indent'];
        $delimiter = $example['delimiter'];
        $separator = $example['separator'];
        $prepend = $example['prepend'];
        $title    = $example['title'];
        $titleRaw = $example['titleRaw'];
        $append   = $example['append'];

        $result = $helper($indent, $delimiter);

        $result->setSeparator($separator);

        if (!empty($prepend)) {
            foreach ($prepend as $text => $raw) {
                $result->prepend($text, $raw);
            }
        }

        $result->set($title, $titleRaw);
        if (!empty($append)) {
            foreach ($append as $text => $raw) {
                $result->append($text, $raw);
            }
        }

        $expected = $example['get'];
        $actual   = $result->get();
        $I->assertEquals($expected, $actual);

        $expected = $example['render'];
        $actual   = (string) $result;
        $I->assertEquals($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('title');

        $result = $locator($indent, $delimiter);

        $result->setSeparator($separator);
        if (!empty($prepend)) {
            foreach ($prepend as $text => $raw) {
                $result->prepend($text, $raw);
            }
        }

        $result->set($title, $titleRaw);

        if (!empty($append)) {
            foreach ($append as $text => $raw) {
                $result->append($text, $raw);
            }
        }


        $expected = $example['get'];
        $actual   = $result->get();
        $I->assertEquals($expected, $actual);

        $expected = $example['render'];
        $actual   = (string) $result;
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'message'   => 'only title',
                'separator' => '',
                'indent'    => '',
                'delimiter' => '',
                'prepend'   => [],
                'title'     => 'Accounting',
                'titleRaw'  => false,
                'append'    => [],
                'get'       => 'Accounting',
                'render'    => '<title>Accounting</title>',
            ],
            [
                'message'   => 'only title escaped',
                'separator' => '',
                'indent'    => '',
                'delimiter' => '',
                'prepend'   => [],
                'title'     => '<Accounting>',
                'titleRaw'  => false,
                'append'    => [],
                'get'       => '&lt;Accounting&gt;',
                'render'    => '<title>&lt;Accounting&gt;</title>',
            ],
            [
                'message'   => 'only title raw',
                'separator' => '',
                'indent'    => '',
                'delimiter' => '',
                'prepend'   => [],
                'title'     => '<Accounting>',
                'titleRaw'  => true,
                'append'    => [],
                'get'       => '<Accounting>',
                'render'    => '<title><Accounting></title>',
            ],
            [
                'message'   => 'only title indent',
                'separator' => '',
                'indent'    => '--',
                'delimiter' => '',
                'prepend'   => [],
                'title'     => 'Accounting',
                'titleRaw'  => true,
                'append'    => [],
                'get'       => 'Accounting',
                'render'    => '--<title>Accounting</title>',
            ],
            [
                'message'   => 'only title delimiter',
                'separator' => '',
                'indent'    => '',
                'delimiter' => '+',
                'prepend'   => [],
                'title'     => 'Accounting',
                'titleRaw'  => true,
                'append'    => [],
                'get'       => 'Accounting',
                'render'    => '<title>Accounting</title>+',
            ],
            [
                'message'   => 'only title prepend',
                'separator' => ' | ',
                'indent'    => '',
                'delimiter' => '',
                'prepend'   => [
                    'Home >'  => false,
                    'Admin >' => false,
                ],
                'title'     => 'Accounting',
                'titleRaw'  => false,
                'append'    => [],
                'get'       => 'Accounting',
                'render'    => '<title>Home &gt; | Admin &gt; | Accounting</title>',
            ],
            [
                'message'   => 'only title append',
                'separator' => ' | ',
                'indent'    => '',
                'delimiter' => '',
                'prepend'   => [],
                'title'     => 'Accounting',
                'titleRaw'  => false,
                'append'    => [
                    '< Admin' => false,
                    '< Home'  => false,
                ],
                'get'       => 'Accounting',
                'render'    => '<title>Accounting | &lt; Admin | &lt; Home</title>',
            ],
            [
                'message'   => 'only title prepend raw',
                'separator' => ' | ',
                'indent'    => '',
                'delimiter' => '',
                'prepend'   => [
                    'Home >'  => true,
                    'Admin >' => true,
                ],
                'title'     => 'Accounting',
                'titleRaw'  => false,
                'append'    => [],
                'get'       => 'Accounting',
                'render'    => '<title>Home > | Admin > | Accounting</title>',
            ],
            [
                'message'   => 'only title append',
                'separator' => ' | ',
                'indent'    => '',
                'delimiter' => '',
                'prepend'   => [],
                'title'     => 'Accounting',
                'titleRaw'  => false,
                'append'    => [
                    '< Admin' => true,
                    '< Home'  => true,
                ],
                'get'       => 'Accounting',
                'render'    => '<title>Accounting | < Admin | < Home</title>',
            ],
        ];
    }
}
