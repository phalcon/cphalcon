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

namespace Phalcon\Tests\Support\Models;

/**
 * Probe for the cloneResult() characterization tests. Records how many times
 * afterFetch() fired, what the record looked like at that moment, and the
 * dirty state a setter observes while assignment is still running.
 */
class InvoicesCloneResultProbe extends Invoices
{
    public $afterFetchCount = 0;

    public $afterFetchSnapshot = [];

    public $declaredSetterCalls = 0;

    public $setterDirtyStates = [];

    public $typedSetterCalls = 0;

    public function afterFetch(): void
    {
        $this->afterFetchCount++;
        $this->afterFetchSnapshot = [
            'dirtyState' => $this->getDirtyState(),
            'inv_id'     => $this->inv_id,
            'inv_title'  => $this->inv_title,
        ];
    }

    /**
     * `inv_title` IS declared public on Invoices, so assignment writes it
     * directly and must never reach this setter.
     */
    public function setInvTitle($value): void
    {
        $this->declaredSetterCalls++;
    }

    /**
     * `isActive` is a typed private property on Invoices. Assignment must go
     * through reflection, never through this setter.
     */
    public function setIsActive(?bool $flag)
    {
        $this->typedSetterCalls++;

        parent::setIsActive($flag);
    }

    /**
     * `probeValue` is deliberately undeclared, so assigning it routes through
     * Model::__set() and therefore through possibleSetter().
     */
    public function setProbeValue($value): void
    {
        $this->setterDirtyStates[] = $this->getDirtyState();
    }
}
