<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Acl;

use Phalcon\Acl\SubjectAware;
use Phalcon\Acl\OperationAware;

/**
 * Class TestOperationSubjectAware
 */
class TestOperationSubjectAware implements OperationAware, SubjectAware
{
    /**
     * @var int
     */
    protected $user;

    /**
     * @var string
     */
    protected $subjectName;

    /**
     * @var string
     */
    protected $operationName;

    /**
     * @param $user
     * @param $subjectName
     * @param $operationName
     */
    public function __construct($user, $subjectName, $operationName)
    {
        $this->user         = $user;
        $this->subjectName = $subjectName;
        $this->operationName     = $operationName;
    }

    /**
     * @return string
     */
    public function getSubjectName(): string
    {
        return $this->subjectName;
    }

    /**
     * @return string
     */
    public function getOperationName(): string
    {
        return $this->operationName;
    }

    /**
     * @return int
     */
    public function getUser()
    {
        return $this->user;
    }
}
