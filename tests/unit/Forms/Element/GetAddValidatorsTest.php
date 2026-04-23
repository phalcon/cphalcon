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

namespace Phalcon\Tests\Unit\Forms\Element;

use Phalcon\Filter\Validation\Validator\Alnum;
use Phalcon\Filter\Validation\Validator\Digit;
use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Forms\Fake\FormsTrait;

use function uniqid;

final class GetAddValidatorsTest extends AbstractUnitTestCase
{
    use FormsTrait;

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-12-05
     */
    public function testFormsElementGetAddValidators(
        string $class
    ): void {
        $name       = uniqid();
        $one        = new StringLength();
        $two        = new Alnum();
        $three      = new Digit();
        $validators = [$one, $two];

        $object = new $class($name);

        $expected = [];
        $actual   = $object->getValidators();
        $this->assertSame($expected, $actual);

        $object->addValidators($validators);

        $expected = $validators;
        $actual   = $object->getValidators();
        $this->assertSame($expected, $actual);

        $object->addValidator($three);

        $validators[] = $three;
        $expected     = $validators;
        $actual       = $object->getValidators();
        $this->assertSame($expected, $actual);
    }

    /**
     * @dataProvider getExamples
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsElementAddValidatorsMergeFalseClearsExisting(
        string $class
    ): void {
        $name   = uniqid();
        $one    = new StringLength();
        $two    = new Alnum();
        $three  = new Digit();
        $object = new $class($name);

        $object->addValidators([$one, $two]);

        // Add $three with merge=false — should discard $one and $two
        $object->addValidators([$three], false);

        $expected = [$three];
        $actual   = $object->getValidators();
        $this->assertSame($expected, $actual);
    }
}
