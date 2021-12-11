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

namespace Phalcon\Tests\Integration\Forms\Element;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Forms\Element\Check;
use Phalcon\Forms\Element\Date;
use Phalcon\Forms\Element\Email;
use Phalcon\Forms\Element\File;
use Phalcon\Forms\Element\Hidden;
use Phalcon\Forms\Element\Numeric;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Element\Radio;
use Phalcon\Forms\Element\Select;
use Phalcon\Forms\Element\Submit;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Element\TextArea;
use Phalcon\Forms\Exception;

use function array_flip;
use function uniqid;

class GetSetFiltersCest
{
    /**
     * Tests Phalcon\Forms\Element\* :: getFilters()/setFilters()/addFilter()
     *
     * @dataProvider getExamples
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function formsElementGetSetAddFilters(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Forms\Element\* - getFilters()/setFilters()/addFilter() - ' . $example[0]);

        $name   = uniqid();
        $data  = [
            'trim',
            'striptags',
        ];
        $flipped = array_flip($data);

        $class   = $example[1];
        $object  = new $class($name);

        $expected = [];
        $actual   = $object->getFilters();
        $I->assertSame($expected, $actual);

        $object->setFilters($flipped);

        $expected = $flipped;
        $actual   = $object->getFilters();
        $I->assertSame($expected, $actual);

        $object->setFilters('lower');

        $expected = 'lower';
        $actual   = $object->getFilters();
        $I->assertSame($expected, $actual);

        $object->addFilter('trim');

        $expected = ['lower', 'trim'];
        $actual   = $object->getFilters();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Forms\Element\* :: setFilters() - exception
     *
     * @dataProvider getExamples
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function formsElementSetFiltersException(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Forms\Element\* - setFilters() exception - ' . $example[0]);

        $I->expectThrowable(
            new Exception(
                "The filter needs to be an array or string"
            ),
            function () use ($example) {
                $name = uniqid();

                $class  = $example[1];
                $object = new $class($name);

                $object->setFilters(1234);
            }
        );
    }

    /**
     * @return string[][]
     */
    private function getExamples(): array
    {
        return [
            ["Check", Check::class],
            ["Date", Date::class],
            ["Email", Email::class],
            ["File", File::class],
            ["Hidden", Hidden::class],
            ["Numeric", Numeric::class],
            ["Password", Password::class],
            ["Radio", Radio::class],
            ["Select", Select::class],
            ["Submit", Submit::class],
            ["Text", Text::class],
            ["TextArea", TextArea::class],
        ];
    }
}
