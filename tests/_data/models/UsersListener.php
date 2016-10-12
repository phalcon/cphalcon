<?php


namespace Phalcon\Test\Models;

use FitCompany\Models\Entities\Activity\Activity;
use FitCompany\Models\Entities\Activity\ActivityParameter;
use FitCompany\Models\Entities\Activity\Type;
use FitCompany\Models\Entities\Competition\Competition;
use FitCompany\Models\Entities\Competition\UserParticipation;
use FitCompany\Models\Entities\General\Achievement;
use FitCompany\Models\Entities\General\Parameter;
use FitCompany\Models\Listeners\BaseListener;
use FitCompany\Models\Repositories\Repositories;
use FitCompany\Models\Repositories\Repository\Company\ActivityTypeSettingsRepository;
use FitCompany\Models\Repositories\Repository\Competition\DepartmentParticipationRepository;
use FitCompany\Models\Repositories\Repository\Competition\UserParticipationRepository;
use FitCompany\Models\Repositories\Repository\Feed\ItemRepository;
use FitCompany\Models\Repositories\Repository\General\AchievementRepository;
use FitCompany\Models\Services\Exceptions\CreateEntityException;
use FitCompany\Models\Services\Exceptions\ServiceException;
use FitCompany\Models\Services\Service\Activity\ActivityService;
use FitCompany\Models\Services\Service\Activity\MapService;
use FitCompany\Models\Services\Service\Company\DepartmentService;
use FitCompany\Models\Services\Service\Competition\DepartmentParticipationService;
use FitCompany\Models\Services\Service\Competition\UserParticipationService;
use FitCompany\Models\Services\Service\Feed\ItemService;
use FitCompany\Models\Services\Service\General\AchievementService;
use FitCompany\Models\Services\Service\Notification\NotificationService;
use FitCompany\Models\Services\Service\User\CompletedAchievementService;
use FitCompany\Models\Services\Service\User\PointsService;
use FitCompany\Models\Services\Services;
use FitCompany\Plugins\Achievement\Interfaces\ActivityRequirementInterface;
use FitCompany\Plugins\EventSourcing\Event\Notification\Activity\UserCollaborated;
use FitCompany\Plugins\EventSourcing\Event\Notification\Mentioned\ActivityMentioned;
use FitCompany\Plugins\EventSourcing\Serializer\SerializerBase;
use FitCompany\Plugins\Storage\ActivityMapStorage;
use FitCompany\Plugins\Storage\ActivityPhotoStorage;
use Phalcon\Events\Event;
use Phalcon\Test\Models\UsersWithListener;

class UsersListener extends \Phalcon\Di\Injectable
{
    public function beforeSave(Event $event, UsersWithListener $usersWithListener)
    {
        $usersWithListener->name = 'test user after event';
        return true;
    }

    public function beforeDelete(Event $event, UsersWithListener $usersWithListener)
    {
    }

}
