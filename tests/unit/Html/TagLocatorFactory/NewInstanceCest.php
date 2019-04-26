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

namespace Phalcon\Test\Unit\Html\TagLocatorFactory;

use Codeception\Example;
use Phalcon\Html\Helper\Anchor;
use Phalcon\Html\TagLocatorFactory;
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
    public function htmlTagLocatorFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Filter\FilterLocatorFactory - newInstance()');
        $factory  = new TagLocatorFactory();
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
    public function htmlTagLocatorFactoryNewInstanceServices(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\FilterLocatorFactory - newInstance() - services ' . $example[0]);
        $factory  = new TagLocatorFactory();
        $instance = $factory->newInstance();

        $class = LocatorInterface::class;
        $I->assertInstanceOf($class, $instance);

        $actual = $instance->has($example[0]);
        $I->assertTrue($actual);
    }

    /**
     * Returns the example data
     */
    private function getData(): array
    {
        return [
            ["a"],
            ["base"],
            ["blockquote"],
            ["body"],
            ["button"],
            ["code"],
            ["comment"],
            ["data"],
            ["datalist"],
            ["doctype"],
            ["element"],
            ["form"],
            ["formClose"],
            ["head"],
            ["header"],
            ["hr"],
            ["img"],
            ["input"],
            ["label"],
            ["link"],
            ["script"],
            ["span"],
            ["style"],
            ["textarea"],
            ["title"],
        ];
    }
}
