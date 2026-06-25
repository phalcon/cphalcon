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

namespace Phalcon\Tests\Unit\Filter\Validation;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\Alpha;
use Phalcon\Tests\AbstractUnitTestCase;

final class AllowEmptyTest extends AbstractUnitTestCase
{
    /**
     * Tests that allowEmpty as a value-list array (e.g. [null, '']) causes
     * the validator to skip validation when the submitted value is in the list,
     * using strict === comparison so that '0' is not treated as empty.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/15491
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-22
     */
    public function testFilterValidationAllowEmptyArrayValueList(): void
    {
        $validation = new Validation();
        $validator  = new Alpha(['allowEmpty' => [null, '']]);
        $validation->add('name', $validator);

        // null → in list → skip → passes
        $this->assertCount(0, $validation->validate(['name' => null]));

        // '' → in list → skip → passes
        $this->assertCount(0, $validation->validate(['name' => '']));

        // '0' → NOT in list → validator runs → Alpha fails '0'
        $this->assertCount(1, $validation->validate(['name' => '0']));

        // valid value → not in list → validator runs → passes
        $this->assertCount(0, $validation->validate(['name' => 'Acme']));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-07
     */
    public function testFilterValidationAllowEmptyFalse(): void
    {
        $data       = ['name' => ''];
        $validation = new Validation();
        $validator  = new Alpha(['allowEmpty' => false]);
        $validation->add('name', $validator);
        $messages = $validation->validate($data);

        $this->assertCount(1, $messages);
    }

    /**
     * Tests that allowEmpty=false with an empty value causes the validator
     * to return false (fail), not silently pass.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16200
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-22
     */
    public function testFilterValidationAllowEmptyFalseWithEmptyValue(): void
    {
        $validation = new Validation();
        $validator  = new Alpha(['allowEmpty' => false]);
        $validation->add('name', $validator);

        // empty string → allowEmpty=false → must fail
        $this->assertCount(1, $validation->validate(['name' => '']));

        // null → allowEmpty=false → must fail
        $this->assertCount(1, $validation->validate(['name' => null]));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-07
     */
    public function testFilterValidationAllowEmptyTrue(): void
    {
        $data       = ['name' => ''];
        $validation = new Validation();
        $validator  = new Alpha(['allowEmpty' => true]);
        $validation->add('name', $validator);
        $messages = $validation->validate($data);

        $this->assertCount(0, $messages);
    }
}
