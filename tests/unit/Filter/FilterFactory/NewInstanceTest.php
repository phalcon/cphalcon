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

namespace Phalcon\Tests\Unit\Filter\FilterFactory;

use Phalcon\Filter\Filter;
use Phalcon\Filter\FilterFactory;
use Phalcon\Filter\FilterInterface;
use Phalcon\Filter\Sanitize\AbsInt;
use Phalcon\Filter\Sanitize\Alnum;
use Phalcon\Filter\Sanitize\Alpha;
use Phalcon\Filter\Sanitize\BoolVal;
use Phalcon\Filter\Sanitize\Email;
use Phalcon\Filter\Sanitize\FloatVal;
use Phalcon\Filter\Sanitize\IntVal;
use Phalcon\Filter\Sanitize\Ip;
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
use Phalcon\Tests\AbstractUnitTestCase;

final class NewInstanceTest extends AbstractUnitTestCase
{
    /**
     * Returns the example data
     */
    public static function getData(): array
    {
        return [
            [Filter::FILTER_ABSINT, AbsInt::class],
            [Filter::FILTER_ALNUM, Alnum::class],
            [Filter::FILTER_ALPHA, Alpha::class],
            [Filter::FILTER_BOOL, BoolVal::class],
            [Filter::FILTER_EMAIL, Email::class],
            [Filter::FILTER_FLOAT, FloatVal::class],
            [Filter::FILTER_INT, IntVal::class],
            [Filter::FILTER_IP, Ip::class],
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

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFilterFilterFactoryNewInstance(): void
    {
        $factory = new FilterFactory();

        $this->assertInstanceOf(FilterInterface::class, $factory->newInstance());
    }

    /**
     * @dataProvider getData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testFilterFilterFactoryNewInstanceServices(
        string $name,
        string $class
    ): void {
        $factory  = new FilterFactory();
        $instance = $factory->newInstance();

        $interface = FilterInterface::class;
        $this->assertInstanceOf($interface, $instance);

        $actual = $instance->get($name);
        $this->assertInstanceOf($class, $actual);
    }
}
