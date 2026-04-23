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
use Phalcon\Filter\Validation\Validator\Email;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\Test;

final class FailsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-08-02
     */
    public function testFilterValidationFailsTrue(): void
    {
        $email      = new Email();

        $validation = new Validation();

        $validation->add('email', $email);
        $this->assertNotEmpty($validation->validate(['email' => 'test@-example.com']));
        $this->assertTrue($validation->fails());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-08-02
     */
    public function testFilterValidationFailsFalse(): void
    {
        $email      = new Email();

        $validation = new Validation();

        $validation->add('email', $email);
        $validation->validate(['email' => 'user@example.com']);
        $this->assertFalse($validation->fails());
    }
}
