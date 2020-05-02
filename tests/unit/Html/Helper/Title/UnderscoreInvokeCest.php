<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Html\Helper\Title;

use Codeception\Example;
use Phalcon\Escaper;
use Phalcon\Html\Helper\Title;
use Phalcon\Html\TagFactory;
use UnitTester;

class UnderscoreInvokeCest
{
    /**
     * Tests Phalcon\Html\Helper\Title :: __invoke()
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @dataProvider getExamples
     * @since        2020-01-07
     */
    public function htmlHelperTitleUnderscoreInvoke(UnitTester $I, Example $example)
    {
        $I->wantToTest('Html\Helper\Title - __invoke() - ' . $example['message']);

        $escaper = new Escaper();
        $helper  = new Title($escaper);

        $result = $helper($example['separator'], $example['indent'], $example['delimiter']);

        if (!empty($example['prepend'])) {
            foreach ($example['prepend'] as $text => $raw) {
                $result->prepend($text, $raw);
            }
        }

        $result->set($example['title'], $example['titleRaw']);

        if (!empty($example['append'])) {
            foreach ($example['append'] as $text => $raw) {
                $result->append($text, $raw);
            }
        }

        $I->assertEquals($example['get'], $result->get());
        $I->assertEquals($example['render'], (string) $result);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('title');

        $result = $locator($example['separator'], $example['indent'], $example['delimiter']);

        if (!empty($example['prepend'])) {
            foreach ($example['prepend'] as $text => $raw) {
                $result->prepend($text, $raw);
            }
        }

        $result->set($example['title'], $example['titleRaw']);

        if (!empty($example['append'])) {
            foreach ($example['append'] as $text => $raw) {
                $result->append($text, $raw);
            }
        }

        $I->assertEquals($example['get'], $result->get());
        $I->assertEquals($example['render'], (string) $result);
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
                'indent'    => null,
                'delimiter' => null,
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
                'indent'    => null,
                'delimiter' => null,
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
                'indent'    => null,
                'delimiter' => null,
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
                'delimiter' => null,
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
                'indent'    => null,
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
                'indent'    => null,
                'delimiter' => null,
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
                'indent'    => null,
                'delimiter' => null,
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
                'indent'    => null,
                'delimiter' => null,
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
                'indent'    => null,
                'delimiter' => null,
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
