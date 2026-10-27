<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Benchmarks\Filter;

use Phalcon\Di\Di;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\Email;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Filter\Validation\Validator\StringLength;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class ValidationBench
{
    /**
     * The name is too short (StringLength) and the email is not valid
     * (Email): 2 messages.
     */
    private const INVALID_DATA = [
        'email' => 'bad',
        'name'  => 'a',
    ];

    private const VALID_DATA = [
        'email' => 'team@phalcon.io',
        'name'  => 'Phalcon',
    ];

    private Validation $validation;

    public function setUp(): void
    {
        Di::reset();

        $this->validation = new Validation();
        $this->validation->add('name', new PresenceOf());
        $this->validation->add('email', new PresenceOf());
        $this->validation->add('email', new Email());
        $this->validation->add('name', new StringLength(['max' => 50, 'min' => 2]));
    }

    public function benchValidate(): void
    {
        $messages = $this->validation->validate(self::VALID_DATA);

        if (0 !== count($messages)) {
            throw new RuntimeException(sprintf('Unexpected count: %d', count($messages)));
        }
    }

    public function benchValidateFails(): void
    {
        $messages = $this->validation->validate(self::INVALID_DATA);

        if (2 !== count($messages)) {
            throw new RuntimeException(sprintf('Unexpected count: %d', count($messages)));
        }
    }
}
