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

namespace Phalcon\Tests\Benchmarks\Encryption;

use Phalcon\Di\Di;
use Phalcon\Encryption\Security;
use Phalcon\Session\Adapter\Noop;
use Phalcon\Session\Manager;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class SecurityBench
{
    private Manager $session;

    private string $token = '';

    private string $tokenKey = '';

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

        $this->newToken(new Security($this->session));
    }

    /**
     * One form request: check the CSRF token of the previous call, then make
     * a new key and token for the next form. checkToken() removes the
     * checked token from the session.
     */
    public function benchCsrf(): void
    {
        $security = new Security($this->session);

        if (true !== $security->checkToken($this->tokenKey, $this->token)) {
            throw new RuntimeException(sprintf('Unexpected value: false for token "%s"', $this->token));
        }

        $this->newToken($security);
    }

    private function newToken(Security $security): void
    {
        $this->tokenKey = (string) $security->getTokenKey();
        $this->token    = (string) $security->getToken();
    }
}
