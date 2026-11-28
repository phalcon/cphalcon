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

namespace Phalcon\Tests\Unit\Auth\Fake;

use Phalcon\Auth\AbstractAuthDispatcherListener;
use Phalcon\Contracts\Auth\Manager;

/**
 * A listener that calls enforce() with a forward handler.
 */
final class FakeForwardListener extends AbstractAuthDispatcherListener
{
    public function __construct(Manager $manager, private mixed $forwardHandler)
    {
        parent::__construct($manager);
    }

    public function check(): bool
    {
        return $this->enforce('index', [], $this->forwardHandler);
    }

    protected function getActionType(): string
    {
        return 'action';
    }
}
