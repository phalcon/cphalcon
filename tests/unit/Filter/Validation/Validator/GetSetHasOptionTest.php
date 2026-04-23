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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator;

use Phalcon\Filter\Validation\Validator\Alnum;
use Phalcon\Filter\Validation\Validator\Alpha;
use Phalcon\Filter\Validation\Validator\Between;
use Phalcon\Filter\Validation\Validator\Callback;
use Phalcon\Filter\Validation\Validator\Confirmation;
use Phalcon\Filter\Validation\Validator\CreditCard;
use Phalcon\Filter\Validation\Validator\Date;
use Phalcon\Filter\Validation\Validator\Digit;
use Phalcon\Filter\Validation\Validator\Email;
use Phalcon\Filter\Validation\Validator\ExclusionIn;
use Phalcon\Filter\Validation\Validator\File;
use Phalcon\Filter\Validation\Validator\Identical;
use Phalcon\Filter\Validation\Validator\InclusionIn;
use Phalcon\Filter\Validation\Validator\Ip;
use Phalcon\Filter\Validation\Validator\Numericality;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Filter\Validation\Validator\Regex;
use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Filter\Validation\Validator\Uniqueness;
use Phalcon\Filter\Validation\Validator\Url;
use Phalcon\Filter\Validation\ValidatorInterface;
use Phalcon\Tests\AbstractUnitTestCase;

use function uniqid;

final class GetSetHasOptionTest extends AbstractUnitTestCase
{
    public static function getExamples(): array
    {
        return [
            [
                Alnum::class,
            ],
            [
                Alpha::class,
            ],
            [
                Between::class,
            ],
            [
                Callback::class,
            ],
            [
                Confirmation::class,
            ],
            [
                CreditCard::class,
            ],
            [
                Date::class,
            ],
            [
                Digit::class,
            ],
            [
                Email::class,
            ],
            [
                ExclusionIn::class,
            ],
            [
                File::class,
            ],
            [
                File\Size\Equal::class,
            ],
            [
                File\Size\Max::class,
            ],
            [
                File\Size\Min::class,
            ],
            [
                File\Resolution\Equal::class,
            ],
            [
                File\Resolution\Max::class,
            ],
            [
                File\Resolution\Min::class,
            ],
            [
                Identical::class,
            ],
            [
                InclusionIn::class,
            ],
            [
                Ip::class,
            ],
            [
                Numericality::class,
            ],
            [
                PresenceOf::class,
            ],
            [
                Regex::class,
            ],
            [
                StringLength::class,
            ],
            [
                StringLength\Min::class,
            ],
            [
                StringLength\Max::class,
            ],
            [
                Uniqueness::class,
            ],
            [
                Url::class,
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2023-09-20
     */
    public function testFilterValidationValidatorGetSetHasOption(
        string $class
    ): void {
        $name      = uniqid('nam-');
        $value     = uniqid('val-');
        $validator = new $class();

        $this->assertInstanceOf(
            ValidatorInterface::class,
            $validator
        );

        $actual = $validator->hasOption($name);
        $this->assertFalse($actual);

        $validator->setOption($name, $value);

        $actual = $validator->hasOption($name);
        $this->assertTrue($actual);

        $expected = $value;
        $actual   = $validator->getOption($name);
        $this->assertSame($expected, $actual);
    }
}
