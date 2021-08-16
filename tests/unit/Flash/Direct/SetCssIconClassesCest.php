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

namespace Phalcon\Test\Unit\Flash\Direct;

use Codeception\Example;
use Phalcon\Escaper;
use Phalcon\Flash\Direct;
use UnitTester;
use const PHP_EOL;

class SetCssIconClassesCest
{
    /**
     * Tests Phalcon\Flash\Direct :: setCssIconClasses()
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-08-13
     */
    public function flashDirectSetCssIconClasses(UnitTester $I, Example $example)
    {
        $I->wantToTest('Flash\Direct - setCssIconClasses() - ' . $example[0]);

        $flash = $this->setupFlash();

        $actual   = $flash->{$example[0]}('test');
        $expected = "<div class=\"{$example[1]}\"><i class=\"%cssIconClasses%\"></i> test</div>" . PHP_EOL;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Flash\Direct :: setCssIconClasses() - custom template
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-08-13
     */
    public function flashDirectSetCssIconClassesCustomTemplate(UnitTester $I, Example $example)
    {
        $I->wantToTest('Flash\Direct - setCssIconClasses() - custom template - ' . $example[0]);

        $template = '<div class="%cssClass%"><i class="%iconCssClass%"></i> %message% '
            . '<button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>'
            . '</div>';
        $flash    = $this->setupFlash();

        $flash->setCustomTemplate($template);
        $actual   = $flash->{$example[0]}('test');
        $expected = "<div class=\"{$example[1]}\"><i class=\"{$example[2]}\"></i> test "
            . '<button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>'
            . '</div>';
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return \string[][]
     */
    private function getExamples(): array
    {
        return [
            [
                'error',
                'errorPhalcon',
                'errorIconPhalcon',
            ],
            [
                'success',
                'successPhalcon',
                'successIconPhalcon',
            ],
            [
                'notice',
                'noticePhalcon',
                'noticeIconPhalcon',
            ],
            [
                'warning',
                'warningPhalcon',
                'warningIconPhalcon',
            ],
        ];
    }

    private function setupFlash(): Direct
    {
        $flash = new Direct(new Escaper());

        $flash
            ->setImplicitFlush(false)
            ->setCssClasses(
                [
                    'error'   => 'errorPhalcon',
                    'success' => 'successPhalcon',
                    'notice'  => 'noticePhalcon',
                    'warning' => 'warningPhalcon',
                ]
            )
            ->setCssIconClasses(
                [
                    'error'   => 'errorIconPhalcon',
                    'success' => 'successIconPhalcon',
                    'notice'  => 'noticeIconPhalcon',
                    'warning' => 'warningIconPhalcon',
                ]
            )
        ;

        return $flash;
    }
}
