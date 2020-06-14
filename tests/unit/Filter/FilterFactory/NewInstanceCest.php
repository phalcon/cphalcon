<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Filter\FilterFactory;

use Codeception\Example;
use Phalcon\Filter;
use Phalcon\Filter\FilterFactory;
use Phalcon\Filter\FilterInterface;
use Phalcon\Filter\Sanitize\AbsInt;
use Phalcon\Filter\Sanitize\Alnum;
use Phalcon\Filter\Sanitize\Alpha;
use Phalcon\Filter\Sanitize\BoolVal;
use Phalcon\Filter\Sanitize\Email;
use Phalcon\Filter\Sanitize\FloatVal;
use Phalcon\Filter\Sanitize\IntVal;
use Phalcon\Filter\Sanitize\Lower;
use Phalcon\Filter\Sanitize\LowerFirst;
use Phalcon\Filter\Sanitize\Regex;
use Phalcon\Filter\Sanitize\Remove;
use Phalcon\Filter\Sanitize\Replace;
use Phalcon\Filter\Sanitize\Special;
use Phalcon\Filter\Sanitize\SpecialFull;
use Phalcon\Filter\Sanitize\StringVal;
use Phalcon\Filter\Sanitize\Striptags;
use Phalcon\Filter\Sanitize\Trim;
use Phalcon\Filter\Sanitize\Upper;
use Phalcon\Filter\Sanitize\UpperFirst;
use Phalcon\Filter\Sanitize\UpperWords;
use Phalcon\Filter\Sanitize\Url;
use UnitTester;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Filter\FilterFactory :: newInstance()
     *
     * @param  UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function filterFilterFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Filter\FilterFactory - newInstance()');
        $factory  = new FilterFactory();

        $I->assertInstanceOf(FilterInterface::class, $factory->newInstance());
    }

    /**
     * Tests Phalcon\Filter\FilterFactory :: newInstance() - services
     *
     * @param        UnitTester $I
     * @param        Example $example
     * @dataProvider getData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function filterFilterFactoryNewInstanceServices(UnitTester $I, Example $example)
    {
        $I->wantToTest(
            'Filter\FilterFactory - newInstance() - services ' . $example[0]
        );

        $factory  = new FilterFactory();
        $instance = $factory->newInstance();

        $I->assertInstanceOf(
            FilterInterface::class,
            $instance
        );

        $I->assertInstanceOf(
            $example[1],
            $instance->get($example[0])
        );
    }

    /**
     * Returns the example data
     */
    private function getData(): array
    {
        return [
            [Filter::FILTER_ABSINT, AbsInt::class],
            [Filter::FILTER_ALNUM, Alnum::class],
            [Filter::FILTER_ALPHA, Alpha::class],
            [Filter::FILTER_BOOL, BoolVal::class],
            [Filter::FILTER_EMAIL, Email::class],
            [Filter::FILTER_FLOAT, FloatVal::class],
            [Filter::FILTER_INT, IntVal::class],
            [Filter::FILTER_LOWER, Lower::class],
            [Filter::FILTER_LOWERFIRST, LowerFirst::class],
            [Filter::FILTER_REGEX, Regex::class],
            [Filter::FILTER_REMOVE, Remove::class],
            [Filter::FILTER_REPLACE, Replace::class],
            [Filter::FILTER_SPECIAL, Special::class],
            [Filter::FILTER_SPECIALFULL, SpecialFull::class],
            [Filter::FILTER_STRING, StringVal::class],
            [Filter::FILTER_STRIPTAGS, Striptags::class],
            [Filter::FILTER_TRIM, Trim::class],
            [Filter::FILTER_UPPER, Upper::class],
            [Filter::FILTER_UPPERFIRST, UpperFirst::class],
            [Filter::FILTER_UPPERWORDS, UpperWords::class],
            [Filter::FILTER_URL, Url::class],
        ];
    }
}
