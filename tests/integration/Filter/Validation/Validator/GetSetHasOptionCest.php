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

namespace Phalcon\Tests\Integration\Filter\Validation\Validator;

use Codeception\Example;
use IntegrationTester;
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

use function uniqid;

class GetSetHasOptionCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\Alnum :: getOption()/hasOption()/setOption()
     *
     * @dataProvider getExamples
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-09-20
     */
    public function filterValidationValidatorGetSetHasOption(
        IntegrationTester $I,
        Example $example
    ) {
        $class = $example['class'];

        $I->wantToTest(
            $class . ' - getOption()/hasOption()/setOption()'
        );

        $name      = uniqid('nam-');
        $value     = uniqid('val-');
        $validator = new $class();

        $I->assertInstanceOf(
            ValidatorInterface::class,
            $validator
        );

        $actual = $validator->hasOption($name);
        $I->assertFalse($actual);

        $validator->setOption($name, $value);

        $actual = $validator->hasOption($name);
        $I->assertTrue($actual);

        $expected = $value;
        $actual   = $validator->getOption($name);
        $I->assertSame($expected, $actual);
    }

    private function getExamples(): array
    {
        return [
            [
                'class' => Alnum::class,
            ],
            [
                'class' => Alpha::class,
            ],
            [
                'class' => Between::class,
            ],
            [
                'class' => Callback::class,
            ],
            [
                'class' => Confirmation::class,
            ],
            [
                'class' => CreditCard::class,
            ],
            [
                'class' => Date::class,
            ],
            [
                'class' => Digit::class,
            ],
            [
                'class' => Email::class,
            ],
            [
                'class' => ExclusionIn::class,
            ],
            [
                'class' => File::class,
            ],
            [
                'class' => File\Size\Equal::class,
            ],
            [
                'class' => File\Size\Max::class,
            ],
            [
                'class' => File\Size\Min::class,
            ],
            [
                'class' => File\Resolution\Equal::class,
            ],
            [
                'class' => File\Resolution\Max::class,
            ],
            [
                'class' => File\Resolution\Min::class,
            ],
            [
                'class' => Identical::class,
            ],
            [
                'class' => InclusionIn::class,
            ],
            [
                'class' => Ip::class,
            ],
            [
                'class' => Numericality::class,
            ],
            [
                'class' => PresenceOf::class,
            ],
            [
                'class' => Regex::class,
            ],
            [
                'class' => StringLength::class,
            ],
            [
                'class' => StringLength\Min::class,
            ],
            [
                'class' => StringLength\Max::class,
            ],
            [
                'class' => Uniqueness::class,
            ],
            [
                'class' => Url::class,
            ],
        ];
    }
}
