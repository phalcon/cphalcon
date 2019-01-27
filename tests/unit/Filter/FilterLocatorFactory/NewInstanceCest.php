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

namespace Phalcon\Test\Unit\Filter\FilterLocatorFactory;

use Codeception\Example;
use Phalcon\Filter\FilterLocator;
use Phalcon\Filter\FilterLocatorFactory;
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
use Phalcon\Service\LocatorInterface;
use UnitTester;

/**
 * Class NewInstanceCest
 */
class NewInstanceCest
{
    /**
     * Tests Phalcon\Filter\FilterLocatorFactory :: newInstance()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function filterFilterLocatorFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Filter\FilterLocatorFactory - newInstance()');
        $factory  = new FilterLocatorFactory();
        $instance = $factory->newInstance();

        $class = LocatorInterface::class;
        $I->assertInstanceOf($class, $instance);
    }

    /**
     * Tests Phalcon\Filter\FilterLocatorFactory :: newInstance() - services
     *
     * @dataProvider getData
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2018-11-13
     */
    public function filterFilterLocatorFactoryNewInstanceServices(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\FilterLocatorFactory - newInstance() - services ' . $example[0]);
        $factory  = new FilterLocatorFactory();
        $instance = $factory->newInstance();

        $class = LocatorInterface::class;
        $I->assertInstanceOf($class, $instance);

        $helper = $instance->get($example[0]);
        $I->assertInstanceOf($example[1], $helper);
    }

    /**
     * Returns the example data
     */
    private function getData(): array
    {
        return [
            [FilterLocator::FILTER_ABSINT, AbsInt::class],
            [FilterLocator::FILTER_ALNUM, Alnum::class],
            [FilterLocator::FILTER_ALPHA, Alpha::class],
            [FilterLocator::FILTER_BOOL, BoolVal::class],
            [FilterLocator::FILTER_EMAIL, Email::class],
            [FilterLocator::FILTER_FLOAT, FloatVal::class],
            [FilterLocator::FILTER_INT, IntVal::class],
            [FilterLocator::FILTER_LOWER, Lower::class],
            [FilterLocator::FILTER_LOWERFIRST, LowerFirst::class],
            [FilterLocator::FILTER_REGEX, Regex::class],
            [FilterLocator::FILTER_REMOVE, Remove::class],
            [FilterLocator::FILTER_REPLACE, Replace::class],
            [FilterLocator::FILTER_SPECIAL, Special::class],
            [FilterLocator::FILTER_SPECIALFULL, SpecialFull::class],
            [FilterLocator::FILTER_STRING, StringVal::class],
            [FilterLocator::FILTER_STRIPTAGS, Striptags::class],
            [FilterLocator::FILTER_TRIM, Trim::class],
            [FilterLocator::FILTER_UPPER, Upper::class],
            [FilterLocator::FILTER_UPPERFIRST, UpperFirst::class],
            [FilterLocator::FILTER_UPPERWORDS, UpperWords::class],
            [FilterLocator::FILTER_URL, Url::class],
        ];
    }
}
