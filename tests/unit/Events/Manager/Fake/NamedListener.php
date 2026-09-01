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

namespace Phalcon\Tests\Unit\Events\Manager\Fake;

/**
 * Plain (non-invokable) object listener. attach() classifies it as a
 * method-named-after-the-event handler (type 2).
 */
class NamedListener
{
    public array $calls = [];

    public function onSomething(object $event): void
    {
        $this->calls[] = 'onSomething';
    }
}
