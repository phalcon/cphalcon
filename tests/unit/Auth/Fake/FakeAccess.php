<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Auth\Fake;

use Phalcon\Auth\Access\AbstractAccess;
use Phalcon\Contracts\Auth\Guard\Guard;

final class FakeAccess extends AbstractAccess
{
    private bool $allowed = false;

    private string $lastAction = '';

    private array $lastContext = [];

    private ?Guard $lastGuard = null;

    public function getLastAction(): string
    {
        return $this->lastAction;
    }

    public function getLastContext(): array
    {
        return $this->lastContext;
    }

    public function getLastGuard(): ?Guard
    {
        return $this->lastGuard;
    }

    public function isAllowed(Guard $guard, string $actionName, array $context = []): bool
    {
        $this->lastGuard   = $guard;
        $this->lastAction  = $actionName;
        $this->lastContext = $context;

        return parent::isAllowed($guard, $actionName, $context);
    }

    public function setAllowed(bool $value): void
    {
        $this->allowed = $value;
    }

    protected function allowedIf(Guard $guard): bool
    {
        return $this->allowed;
    }
}
