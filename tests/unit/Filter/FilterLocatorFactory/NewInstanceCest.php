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
use Phalcon\Filter\FilterLocatorFactory;
use Phalcon\Service\LocatorInterface;
use UnitTester;
use Phalcon\Filter\Sanitize\AbsInt;
use Phalcon\Filter\Sanitize\Alnum;
use Phalcon\Filter\Sanitize\Alpha;
use Phalcon\Filter\Sanitize\BoolVal;
use Phalcon\Filter\Sanitize\Email;
use Phalcon\Filter\Sanitize\FloatVal;
use Phalcon\Filter\Sanitize\FloatValCast;
use Phalcon\Filter\Sanitize\IntVal;
use Phalcon\Filter\Sanitize\IntValCast;
use Phalcon\Filter\Sanitize\Lower;
use Phalcon\Filter\Sanitize\LowerFirst;
use Phalcon\Filter\Sanitize\Regex;
use Phalcon\Filter\Sanitize\Remove;
use Phalcon\Filter\Sanitize\Replace;
use Phalcon\Filter\Sanitize\Special;
use Phalcon\Filter\Sanitize\StringVal;
use Phalcon\Filter\Sanitize\Striptags;
use Phalcon\Filter\Sanitize\Trim;
use Phalcon\Filter\Sanitize\Upper;
use Phalcon\Filter\Sanitize\UpperFirst;
use Phalcon\Filter\Sanitize\UpperWords;
use Phalcon\Filter\Sanitize\Url;

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
        $factory = new FilterLocatorFactory();
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function filterFilterLocatorFactoryNewInstanceServices(UnitTester $I, Example $example)
    {
        $I->wantToTest('Filter\FilterLocatorFactory - newInstance() - services ' . $example[0]);
        $factory = new FilterLocatorFactory();
        $instance = $factory->newInstance();

        $class = LocatorInterface::class;
        $I->assertInstanceOf($class, $instance);

        $helper = $instance->get($example[0]);
        $I->assertInstanceOf($example[1], $helper);
    }

    private function getData(): array
    {
        return [
            ['absint', AbsInt::class],
            ['alnum', Alnum::class],
            ['alpha', Alpha::class],
            ['alphanum', Alnum::class],
            ['bool', BoolVal::class],
            ['email', Email::class],
            ['float', FloatVal::class],
            ['float!', FloatValCast::class],
            ['int', IntVal::class],
            ['int!', IntValCast::class],
            ['lower', Lower::class],
            ['lowerFirst', LowerFirst::class],
            ['regex', Regex::class],
            ['remove', Remove::class],
            ['replace', Replace::class],
            ['special_chars', Special::class],
            ['string', StringVal::class],
            ['striptags', Striptags::class],
            ['trim', Trim::class],
            ['upper', Upper::class],
            ['upperFirst', UpperFirst::class],
            ['upperWords', UpperWords::class],
            ['url', Url::class],
        ];
    }
}
