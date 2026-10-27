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

namespace Phalcon\Tests\Benchmarks\Session;

use Phalcon\Di\Di;
use Phalcon\Session\Adapter\Noop;
use Phalcon\Session\Bag;
use Phalcon\Session\Manager;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class SessionBench
{
    private Bag $bag;

    private int $counter = 0;

    private Manager $session;

    public function setUp(): void
    {
        Di::reset();

        $this->session = new Manager();
        $this->session->setAdapter(new Noop());
        $this->session->start();

        if (PHP_SESSION_ACTIVE !== $this->session->status()) {
            throw new RuntimeException(
                sprintf('Unexpected session status: %d', $this->session->status())
            );
        }

        $this->session->set('name', 'phalcon');

        $this->bag = new Bag($this->session, 'user');
    }

    /**
     * Bag::set() writes the data of the bag to the session on each call.
     */
    public function benchBagSet(): void
    {
        $this->counter++;

        $this->bag->set('id', $this->counter);

        $actual = $this->bag->get('id');
        if ($this->counter !== $actual) {
            throw new RuntimeException(sprintf('Unexpected value: %s', var_export($actual, true)));
        }
    }

    public function benchGet(): void
    {
        $actual = $this->session->get('name');

        if ('phalcon' !== $actual) {
            throw new RuntimeException(sprintf('Unexpected value: %s', var_export($actual, true)));
        }
    }

    /**
     * set() of a key that exists, with a new value on each call.
     */
    public function benchSet(): void
    {
        $this->counter++;

        $this->session->set('counter', $this->counter);

        $actual = $this->session->get('counter');
        if ($this->counter !== $actual) {
            throw new RuntimeException(sprintf('Unexpected value: %s', var_export($actual, true)));
        }
    }
}
