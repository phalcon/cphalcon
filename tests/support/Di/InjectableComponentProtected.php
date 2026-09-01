<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Support\Di;

use Phalcon\Di\Injectable as AbstractInjectable;

class InjectableComponentProtected extends AbstractInjectable
{
    protected $widget = null;

    /**
     * Returns the protected property directly, bypassing the magic getter, so
     * tests can observe whether `__get()` populated the declared property.
     */
    public function getWidgetRaw()
    {
        return $this->widget;
    }
}
