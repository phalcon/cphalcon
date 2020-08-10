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

namespace Phalcon\Test\Models;

use Phalcon\Mvc\ModelInterface;

use function is_string;

/**
 * Class InvoicesExtended
 */
class InvoicesExtended extends Invoices
{
    /**
     * @param array|string|null $parameters
     *
     * @return ModelInterface|null
     */
    public static function findFirst($parameters = null): ?ModelInterface
    {
        if (is_string($parameters)) {
            return parent::findFirstByInvId($parameters);
        }

        return parent::findFirst($parameters);
    }
}
